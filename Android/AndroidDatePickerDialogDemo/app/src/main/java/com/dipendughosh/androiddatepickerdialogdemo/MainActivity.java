package com.dipendughosh.androiddatepickerdialogdemo;

import android.app.DatePickerDialog;
import android.app.Dialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.Toast;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity {

    private Button btnShowDate;
    private int year_x;
    private int month_x;
    private int day_x;
    private static final int DIALOG_ID = 0;
    private DatePickerDialog.OnDateSetListener kDatePickerListner = new DatePickerDialog.OnDateSetListener() {
        @Override
        public void onDateSet(DatePicker view, int year, int month, int dayOfMonth) {
            year_x = year;
            month_x = month + 1;
            day_x = dayOfMonth;
            Toast.makeText(MainActivity.this, day_x + " - " + month_x + " - " + year_x, Toast.LENGTH_SHORT).show();
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final Calendar cal = Calendar.getInstance();
        year_x = cal.get(Calendar.YEAR);
        month_x = cal.get(Calendar.MONTH);
        day_x = cal.get(Calendar.DAY_OF_MONTH);

        showDateDialogOnButtonClick();
    }

    @Override
    protected Dialog onCreateDialog(int id) {
        if (id == DIALOG_ID) {
            return new DatePickerDialog(MainActivity.this, kDatePickerListner, year_x, month_x, day_x);
        }
        return null;
    }

    private void showDateDialogOnButtonClick() {
        btnShowDate = (Button) findViewById(R.id.btnShowDate);
        btnShowDate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                showDialog(DIALOG_ID);
            }
        });
    }
}
