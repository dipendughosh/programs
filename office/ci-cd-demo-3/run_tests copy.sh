#!/bin/bash

if [ -d "allure-results" ]; then
    rm -rf allure-results
fi

if [ -d "allure-report" ]; then
    mkdir -p allure-results/history
    cp -r allure-report/history/* allure-results/history/
fi

echo "Running py test"
cd py-test
directories=$(find . -maxdepth 1 -mindepth 1 -type d -exec basename {} \;)
for dir in $directories; do
    if [ "$dir" != ".pytest_cache" ] && [ "$dir" != "__pycache__" ]; then
        pytest --capture=no -o junit_logging=all --junitxml=../allure-results/report-pytest-$dir.xml --log-level info $dir --testsuite-name=$dir
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
directories=$(find . -maxdepth 1 -mindepth 1 -type d -exec basename {} \;)
for dir in $directories; do
    echo "Processing directory: $dir"
    cd $dir
    if [ ! -f "go.mod" ]; then
        go mod init $dir
    fi
    go test -v ./... | go-junit-report > ../../allure-results/report-gotest-$dir.xml
    cd ..
done
echo "Completed go test"

cd ..

allure generate allure-results -c -o allure-report
echo "Allure report generated successfully in the 'allure-report' directory."
allure open --port 8888 allure-report
