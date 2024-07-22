# MODIFIED VERSION OF https://github.com/fescobar/allure-docker-service/blob/master/allure-docker-api-usage/send_results.py

import sys, os, requests, json, base64

if len(sys.argv) != 4:
    print("Not enough arguments supplied. Supply [results_directory] [project_id (tag)] [get_url]")
    exit(1)

allure_results_directory = sys.argv[1]

# allure_server = os.getenv("ALLURE_SERVER")
# allure_server = "http://10.36.79.67:5050"
allure_server = "http://10.39.42.232:5050"

if allure_server is None:
    print("ALLURE_SERVER not set. Exiting")
    exit(1)

project_id = sys.argv[2].replace(".","-")


if sys.argv[3] == "get_url":
    projects_url = f"{allure_server}/allure-docker-service/projects/{project_id}"
    try:
        response = requests.get(projects_url)

        response.raise_for_status()

        json_response = response.json()
        report_links = json_response['data']['project']['reports']

        if len(report_links) < 2:
            print("Did not return report links properly : ", report_links)
            exit(1)
        print(report_links[1])
        exit(0)

    except requests.exceptions.RequestException as e:
        print(f"Error getting projects : {e}")
        exit(1)


if sys.argv[3] == "send_results":
    # current_directory = os.path.dirname(os.path.realpath(__file__))
    results_directory = allure_results_directory
    print('RESULTS DIRECTORY PATH: ' + results_directory)

    files = os.listdir(results_directory)

    print('FILES:')
    results = []
    for file in files:
        result = {}

        file_path = results_directory + "/" + file
        print(file_path)

        if os.path.isfile(file_path):
            try:
                with open(file_path, "rb") as f:
                    content = f.read()
                    if content.strip():
                        b64_content = base64.b64encode(content)
                        result['file_name'] = file
                        result['content_base64'] = b64_content.decode('UTF-8')
                        results.append(result)
                    else:
                        print('Empty File skipped: '+ file_path)
            finally :
                f.close()
        else:
            print('Directory skipped: '+ file_path)

    headers = {'Content-type': 'application/json'}
    request_body = {
        "results": results
    }
    json_request_body = json.dumps(request_body)

    ssl_verification = True

    print("------------------SEND-RESULTS------------------")
    response = requests.post(f'{allure_server}/allure-docker-service/send-results?project_id={project_id}&force_project_creation=true', headers=headers, data=json_request_body, verify=ssl_verification)
    print("STATUS CODE:")
    print(response.status_code)
    print("RESPONSE:")
    json_response_body = json.loads(response.content)
    json_prettier_response_body = json.dumps(json_response_body, indent=4, sort_keys=True)
    print(json_prettier_response_body)


    try:
        response = requests.get(f"{allure_server}/allure-docker-service/generate-report?project_id={project_id}")
        response.raise_for_status()  # Raise an exception if the request was not successful (status code >= 400)
        print("Generated report sucessfully")
    except requests.exceptions.RequestException as e:
        print(f"Couldn't generate report: {e}")
        exit(1)
    print( f"{allure_server}/allure-docker-service/projects/{project_id}/reports/latest/index.html")

    # get the project type from allure_results_directory 

    allure_results_directory = allure_results_directory.replace("./", "")
    with open(allure_results_directory+".log", 'w') as file:
        file.write(f"{allure_server}/allure-docker-service/projects/{project_id}/reports/latest/index.html")
    exit(0)
exit(1)

