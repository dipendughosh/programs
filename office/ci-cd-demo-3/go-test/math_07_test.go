//go:build go_test_07

package math

import (
	"fmt"
	"os"
	"testing"
	"time"
)

func TestAdd07(t *testing.T) {
	if Add(2, 3) != 5 {
		t.Errorf("expected 5, got %d", Add(2, 3))
	}
	if Add(-1, 1) != 0 {
		t.Errorf("expected 0, got %d", Add(-1, 1))
	}
	if Add(-1, -1) != -2 {
		t.Errorf("expected -2, got %d", Add(-1, -1))
	}
}

func TestSubtract07(t *testing.T) {
	if Subtract(5, 3) != 2 {
		t.Errorf("expected 2, got %d", Subtract(5, 3))
	}
	if Subtract(-1, -1) != 0 {
		t.Errorf("expected 0, got %d", Subtract(-1, -1))
	}
	if Subtract(3, 5) != -2 {
		t.Errorf("expected -2, got %d", Subtract(3, 5))
	}
}

func TestMultiply07(t *testing.T) {
	if Multiply(2, 3) != 6 {
		t.Errorf("expected 6, got %d", Multiply(2, 3))
	}
	if Multiply(-1, 1) != -1 {
		t.Errorf("expected -1, got %d", Multiply(-1, 1))
	}
	if Multiply(-1, -1) != 1 {
		t.Errorf("expected 1, got %d", Multiply(-1, -1))
	}
}

func TestDivide07(t *testing.T) {
	result, err := Divide(6, 3)
	if err != nil || result != 2 {
		t.Errorf("expected 2, got %d", result)
	}
	result, err = Divide(-1, 1)
	if err != nil || result != -1 {
		t.Errorf("expected -1, got %d", result)
	}
	result, err = Divide(-1, -1)
	if err != nil || result != 1 {
		t.Errorf("expected 1, got %d", result)
	}
	_, err = Divide(1, 0)
	if err == nil {
		t.Errorf("expected error, got nil")
	}
}

func TestWithAllure07(t *testing.T) {
	performAction(t)
	t.Run("Checking result", func(t *testing.T) {
		// Your result checking code here
		if 1 != 1 {
			t.Errorf("Assertion failed")
		}
	})
	fmt.Fprintf(os.Stdout, "##teamcity[testSuiteFinished name='pytest' timestamp='%s']\n", time.Now().Format("2006-01-02T15:04:05"))
	fmt.Fprintf(os.Stdout, "##teamcity[testSuiteStarted name='pytest' timestamp='%s']\n", time.Now().Format("2006-01-02T15:04:05"))
	fmt.Fprintf(os.Stdout, "##teamcity[testStarted name='test_with_allure' timestamp='%s']\n", time.Now().Format("2006-01-02T15:04:05"))
	fmt.Fprintf(os.Stdout, "##teamcity[testFailed name='test_with_allure' message='Assertion failed' details='This is additional information' timestamp='%s']\n", time.Now().Format("2006-01-02T15:04:05"))
	fmt.Fprintf(os.Stdout, "##teamcity[testFinished name='test_with_allure' timestamp='%s']\n", time.Now().Format("2006-01-02T15:04:05"))
}
