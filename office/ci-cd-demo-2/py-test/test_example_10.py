# test_example.py
import time
import allure
import logging

logging.basicConfig(level=logging.INFO)

def add(a, b):
    time.sleep(1/100)
    c = a + b
    logging.info("Add - " + str(a) + " + " + str(b) + " = " + str(c))
    return c

def subtract(a, b):
    time.sleep(1/100)
    c = a - b
    logging.info("Subtract - " + str(a) + " - " + str(b) + " = " + str(c))
    return c

def multiply(a, b):
    time.sleep(1/100)
    c = a * b
    logging.info("Multiply - " + str(a) + " * " + str(b) + " = " + str(c))
    return c

def divide(a, b):
    time.sleep(1/100)
    if b == 0:
        raise ValueError("Cannot divide by zero")
    c = a / b
    logging.info("Divide - " + str(a) + " / " + str(b) + " = " + str(c))
    return c

def test_add_10():
    assert add(2, 3) == 5
    assert add(-1, 1) == 0
    assert add(-1, -1) == -2

def test_subtract_10():
    assert subtract(5, 3) == 2
    assert subtract(-1, -1) == 0
    assert subtract(3, 5) == -2

def test_multiply_10():
    assert multiply(2, 3) == 6
    assert multiply(-1, 1) == -1
    assert multiply(-1, -1) == 1

def test_divide_10():
    assert divide(6, 3) == 2
    assert divide(-1, 1) == -1
    assert divide(-1, -1) == 1
    try:
        divide(1, 0)
    except ValueError as e:
        assert str(e) == "Cannot divide by zero"

@allure.step("Performing action")
def perform_action():
    # Your action code here
    allure.attach("Action", "Performed an action")

def test_with_allure_10():
    perform_action()
    print("Checking prints")
    with allure.step("Checking result"):
        # Your result checking code here
        assert True, "Assertion failed"
    allure.attach("Additional info", "This is additional information")

def test_with_logs_10():
    logging.info("This is an info log message")
    logging.warning("This is a warning log message")
    logging.info("This is an INFO log message")
    logging.warning("This is a WARNING log message")
    logging.error("This is an ERROR log message")
    logging.critical("This is a CRITICAL log message")
    assert True
