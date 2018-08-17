package com.dipendughosh.sharedprefsdemo;

import android.content.Intent;
import android.content.SharedPreferences;
import android.support.v4.content.SharedPreferencesCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Date;

public class MainActivity extends AppCompatActivity {

    public static final String SHAREDPREF_SET = "da App Times";
    public static final String SHAREDPREF_ITEM_START_TIME = "StartTime";
    private TextView txtCurrentTime;
    private TextView txtLastTime;

    private SharedPreferenceConfig preferenceConfig;
    private EditText username;
    private EditText user_password;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        displayCurrentTime();
        displayLastStartTime();

        storeStartTimeToSharedPreferences();

        preferenceConfig = new SharedPreferenceConfig(getApplicationContext());

        username = findViewById(R.id.username);
        user_password = findViewById(R.id.user_password);

        if(preferenceConfig.readLoginStatus()) {
            startActivity(new Intent(this, SuccessActivity.class));
            Toast.makeText(this, "Logged In already", Toast.LENGTH_SHORT).show();
            finish();
        }
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

        txtLastTime = (TextView) findViewById(R.id.txtLastTime);
        txtLastTime.setText(text);

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

    public void loginUser(View view) {
        String uname = username.getText().toString();
        String u_password = user_password.getText().toString();

        if( uname.equals(getResources().getString(R.string.user_name)) && u_password.equals(getResources().getString(R.string.user_password))) {

            startActivity(new Intent(this, SuccessActivity.class));
            preferenceConfig.writeLoginstatus(true);
            Toast.makeText(this, "Login Successful", Toast.LENGTH_SHORT).show();
            finish();
        }
        else {
            Toast.makeText(this, "Login Faild Try Again", Toast.LENGTH_SHORT).show();
            username.setText("");
            user_password.setText("");
        }
    }
}
