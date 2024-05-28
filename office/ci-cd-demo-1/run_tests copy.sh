#!/bin/bash

if [ -d "allure-results" ]; then
    rm -rf allure-results
fi

if [ -d "allure-report" ]; then
    mkdir -p allure-results/history
    cp -r allure-report/history/* allure-results/history/
fi

# Run pytest with JUnit XML output
echo "Running py test"
cd py-test
pytest --capture=no -o junit_logging=all --junitxml=../allure-results/report-pytest-1.xml --log-level info py-test-1 --testsuite-name="py-test-1"
pytest --capture=no -o junit_logging=all --junitxml=../allure-results/report-pytest-2.xml --log-level info py-test-2 --testsuite-name="py-test-2"
echo "Completed py test"

if ! command -v go-junit-report &> /dev/null; then
    go install github.com/jstemmer/go-junit-report/v2@latest
    export PATH=$PATH:$(go env GOPATH)/bin
fi

cd ..
# Run Go tests and generate JUnit XML report
echo "Running go test"
cd go-test/go-test-1
if [ ! -f "go.mod" ]; then
    go mod init go-test-1
fi
go test -v ./... | go-junit-report > ../../allure-results/report-gotest-1.xml

cd ../..

cd go-test/go-test-2
if [ ! -f "go.mod" ]; then
    go mod init go-test-2
fi
go test -v ./... | go-junit-report > ../../allure-results/report-gotest-2.xml
echo "Completed go test"

cd ../..

allure generate allure-results -c -o allure-report
echo "Allure report generated successfully in the 'allure-report' directory."
allure open --port 8888 allure-report
