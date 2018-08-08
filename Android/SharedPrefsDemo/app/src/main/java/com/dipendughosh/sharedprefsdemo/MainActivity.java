package com.dipendughosh.sharedprefsdemo;

import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import java.util.Date;

public class MainActivity extends AppCompatActivity {

    public static final String SHAREDPREF_SET = "da App Times";
    public static final String SHAREDPREF_ITEM_START_TIME = "StartTime";
    private TextView txtCurrentTime;
    private TextView txtLastTime;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        displayCurrentTime();
        displayLastStartTime();

        storeStartTimeToSharedPreferences();
    }

    private void displayCurrentTime() {

        Date currentTime = new Date();
        String text = "The current time is " + currentTime.toString();

        txtCurrentTime = (TextView) findViewById(R.id.txtCurrentTime);
        txtCurrentTime.setText(text);
    }

    private void displayLastStartTime() {

        String lastStartTime = getLastStartTimeFromSharedPreferences();
        String text = "The last start time is " + lastStartTime;

        txtLastTime= (TextView) findViewById(R.id.txtLastTime);
        txtLastTime(text);

    }

    private String getLastStartTimeFromSharedPreferences() {

        SharedPreferences prefs = getSharedPreferences(SHAREDPREF_SET, MODE_PRIVATE);
        String extractedText = prefs.getString(SHAREDPREF_ITEM_START_TIME, "No Time Recorded");
        return extractedText;
    }

    private void storeStartTimeToSharedPreferences() {

        String text = new Date().toString();

        SharedPreferences prefs = getSharedPreferences(SHAREDPREF_SET, MODE_PRIVATE);
        SharedPreferences.Editor editor = prefs.edit();
        editor.putString(SHAREDPREF_ITEM_START_TIME, text);
        editor.commit();
    }
}
