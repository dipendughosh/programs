package com.dipendughosh.servicedemo;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void startService(View view) {
        Intent intent = new Intent(MainActivity.this, TheService.class);
        startService(intent);
    }

    public void stopService(View view) {
        Intent intent = new Intent(MainActivity.this, TheService.class);
        stopService(intent);
    }

    public void startServiceIntent(View view) {
        Intent intent = new Intent(MainActivity.this, MyService.class);
        startService(intent);
    }

    public void stopServiceIntent(View view) {
        Intent intent = new Intent(MainActivity.this, MyService.class);
        stopService(intent);
    }
}
