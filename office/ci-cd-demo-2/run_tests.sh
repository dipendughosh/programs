#!/bin/bash

if [ -d "allure-results" ]; then
    rm -rf allure-results
fi

if [ -d "allure-report" ]; then
    mkdir -p allure-results/history
    cp -r allure-report/history/* allure-results/history/
fi
timestamp=$(date -u +"%Y-%m-%dT%H:%M:%SZ")
echo "Running py test"
cd py-test
# directories=$(find . -maxdepth 1 -mindepth 1 -type d -exec basename {} \;)
directories=("test_example_01" "test_example_02" "test_example_03" "test_example_04" "test_example_05" "test_example_06" "test_example_07" "test_example_08" "test_example_09" "test_example_10")
# directories=("go_test_1")
for dir in "${directories[@]}"; do
    if [ "$dir" != ".pytest_cache" ] && [ "$dir" != "__pycache__" ]; then
        xml_file="../allure-results/report-pytest-$dir.xml"
        pytest --capture=no -o junit_logging=all --junitxml=$xml_file --log-level info --testsuite-name=$dir -k $dir
        xmlstarlet ed -u "//testsuite/@timestamp" -v "$timestamp" "$xml_file" > temp.xml && mv temp.xml "$xml_file"
    else
        echo "Skipping directory: $dir"
    fi
done
echo "Completed py test"
cd ..

if ! command -v go-junit-report &> /dev/null; then
    go install github.com/jstemmer/go-junit-report/v2@latest
    export PATH=$PATH:$(go env GOPATH)/bin
fi
echo "Running go test"
cd go-test
# directories=$(find . -maxdepth 1 -mindepth 1 -type d -exec basename {} \;)
directories=("go_test_01" "go_test_02" "go_test_03" "go_test_04" "go_test_05" "go_test_06" "go_test_07" "go_test_08" "go_test_09" "go_test_10")
# directories=("go_test_1")
for dir in "${directories[@]}"; do
    echo "Processing directory: $dir"
    if [ ! -f "go.mod" ]; then
        go mod init go-tests
    fi
    xml_file="../allure-results/report-gotest-$dir.xml"
    go test -v -tags $dir ./... | go-junit-report > $xml_file
    xmlstarlet ed -u "//testsuite/@name" -v "$dir" "$xml_file" > temp.xml && mv temp.xml "$xml_file"
    xmlstarlet ed -u "//testsuite/@timestamp" -v "$timestamp" "$xml_file" > temp.xml && mv temp.xml "$xml_file"
done
echo "Completed go test"

cd ..

allure generate allure-results -c -o allure-report
echo "Allure report generated successfully in the 'allure-report' directory."
allure open --port 8888 allure-report
