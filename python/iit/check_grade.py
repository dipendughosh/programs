from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# User credentials
user_id = 'cs23m509'
password = 'L7p8Cnxs6NG'

# Initialize WebDriver for Firefox
driver = webdriver.Chrome()

try:
    # Open the website
    driver.get("https://workflow-elearn.iitm.ac.in/")

    # Find the element
    user_id_field = WebDriverWait(driver, 10).until(EC.visibility_of_element_located((By.NAME, "username")))

    # Get the name attribute
    name_attribute = user_id_field.get_attribute("name")

    # Get the id attribute
    id_attribute = user_id_field.get_attribute("id")

    # Print the attributes
    print("Name Attribute:", name_attribute)
    print("ID Attribute:", id_attribute)

    # Find and fill the user ID field
    user_id_field = driver.find_element(By.NAME, "username")  # Replace with the actual name or ID of the field
    user_id_field.send_keys(user_id)

    # Find and fill the password field
    password_field = driver.find_element(By.NAME, "password")  # Replace with the actual name or ID of the field
    password_field.send_keys(password)

    # Submit the login form
    password_field.send_keys(Keys.RETURN)

    # Wait for the page to load and navigate to the Grade Info tab
    WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.LINK_TEXT, "Grade Info"))  # Adjust the locator as needed
    ).click()

    # Wait for the Grade Info page to load
    WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.ID, "course_table"))  # Adjust the locator as needed
    )

    # Check for the specific course
    courses = driver.find_elements(By.XPATH, "//tr[td[text()='CS6530W']]")

    if courses:
        course = courses[0]
        grade = course.find_element(By.XPATH, "td[@class='grade']").text  # Adjust based on actual HTML structure
        if grade:
            print(f"CourseNo CS6530W has a grade: {grade}")
        else:
            print("CourseNo CS6530W does not have a grade.")
    else:
        print("CourseNo CS6530W not found.")

finally:
    # Close the WebDriver
    driver.quit()
