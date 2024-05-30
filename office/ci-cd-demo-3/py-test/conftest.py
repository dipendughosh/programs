import pytest
import xml.etree.ElementTree as ET
import logging

# logger = logging.getLogger(__name__)
# logging.basicConfig(level=logging.INFO)

def pytest_addoption(parser):
    parser.addoption(
        "--testsuite-name", action="store", default=None, help="Set the testsuite name in JUnit XML"
    )

@pytest.hookimpl(tryfirst=True)
def pytest_configure(config):
    testsuite_name = config.getoption("--testsuite-name")
    if testsuite_name:
        config.testsuite_name = testsuite_name
        # logger.info(f"Setting testsuite name to: {testsuite_name}")

@pytest.hookimpl(tryfirst=True)
def pytest_unconfigure(config):
    testsuite_name = getattr(config, 'testsuite_name', None)
    if testsuite_name:
        path = config.option.xmlpath
        if path:
            tree = ET.parse(path)
            for testsuite in tree.findall("testsuite"):
                testsuite.set("name", testsuite_name)
                # logger.info(f"Modified testsuite name to: {testsuite_name}")
                # Print out the entire testsuite attributes for debugging
                # logger.info(f"Testsuite attributes: {testsuite.attrib}")
            tree.write(path)
