package com.dipendughosh.androiddatepickerdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Button btnShowDate;
    private DatePicker datePicker;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        showDate();
    }

    private void showDate() {
        datePicker = (DatePicker) findViewById(R.id.simpleDatePicker);
        btnShowDate = (Button) findViewById(R.id.btnShowDate);

        btnShowDate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, datePicker.getDayOfMonth() + " : " + datePicker.getMonth() + " : " + datePicker.getYear(), Toast.LENGTH_SHORT).show();
            }
        });
    }
}
