package com.dipendughosh.androidtimepickerdemo;

import android.os.Build;
import android.support.annotation.RequiresApi;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TimePicker;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Button btnShowTime;
    private TimePicker timePicker;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        showTime();
    }
    
    public void showTime() {
        timePicker = (TimePicker) findViewById(R.id.simpleTimePicker);
        btnShowTime = (Button) findViewById(R.id.btnShowTime);
        timePicker.setIs24HourView(true);
        btnShowTime.setOnClickListener(new View.OnClickListener() {
            @RequiresApi(api = Build.VERSION_CODES.M)
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, timePicker.getHour() + " : " + timePicker.getMinute(), Toast.LENGTH_SHORT).show();
            }
        });
    }
}
