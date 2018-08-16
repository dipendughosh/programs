package com.dipendughosh.upbuttonforlowlevelactivitiestoactionbar;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @SuppressLint("RestrictedApi")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //getSupportActionBar().setDefaultDisplayHomeAsUpEnabled(true);
    }

    public void openA(View view) {
        startActivity(new Intent(this, AActivity.class));
    }
}
