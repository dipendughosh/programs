package com.dipendughosh.analogdigitalclockdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AnalogClock;
import android.widget.Button;
import android.widget.DigitalClock;

public class MainActivity extends AppCompatActivity {

    private static Button buttonSbm;
    private static DigitalClock digital;
    private static AnalogClock analog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        OnButtonClickListener();
    }

    public  void OnButtonClickListener() {
        buttonSbm = (Button)findViewById(R.id.button);
        digital = (DigitalClock)findViewById(R.id.digitalClock);
        analog = (AnalogClock)findViewById(R.id.analogClock);

        buttonSbm.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        if(digital.getVisibility() == DigitalClock.GONE) {
                            digital.setVisibility(DigitalClock.VISIBLE);
                            analog.setVisibility(AnalogClock.GONE);
                        } else {
                            digital.setVisibility(DigitalClock.GONE);
                            analog.setVisibility(AnalogClock.VISIBLE);
                        }
                    }
                }
        );

    }
}
