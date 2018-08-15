package com.dipendughosh.androidtimepickerdialogdemo;

import android.app.Dialog;
import android.app.TimePickerDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TimePicker;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Button btnShowTime;
    private static final int DIALOG_ID = 0;
    private int hour_x;
    private int minute_X;
    protected TimePickerDialog.OnTimeSetListener kTimePickerListner = new TimePickerDialog.OnTimeSetListener() {
        @Override
        public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
            hour_x = hourOfDay;
            minute_X = minute;
            Toast.makeText(MainActivity.this, hour_x + " : " + minute, Toast.LENGTH_SHORT).show();
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        showTimePickerDialog();
    }

    @Override
    protected Dialog onCreateDialog(int id) {
        if (id == DIALOG_ID) {
            return new TimePickerDialog(MainActivity.this, kTimePickerListner, hour_x, minute_X, false);
        }
        return null;
    }

    private void showTimePickerDialog() {
        btnShowTime = (Button) findViewById(R.id.btnShowTime);
        btnShowTime.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                showDialog(DIALOG_ID);
            }
        });
    }
}
