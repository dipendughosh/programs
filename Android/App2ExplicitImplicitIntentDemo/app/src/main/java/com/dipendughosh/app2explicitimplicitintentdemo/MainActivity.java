package com.dipendughosh.app2explicitimplicitintentdemo;

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

    public void openA1fromApp1(View view) {
        Intent intent = new Intent("com.dipendughosh.app1explicitimplicitintentdemo.App1A1Activity");
        startActivity(intent);
    }
}
