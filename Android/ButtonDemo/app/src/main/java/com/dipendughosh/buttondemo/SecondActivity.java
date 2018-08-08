package com.dipendughosh.buttondemo;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class SecondActivity extends AppCompatActivity {

    private Button btnOnSecond;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        setupNavigationButton();
    }

    private void setupNavigationButton() {
        btnOnSecond = (Button) findViewById(R.id.btnOnSecond);
        btnOnSecond.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(SecondActivity.this, "You clicked it on 2nd screen!", Toast.LENGTH_LONG).show();

                startActivity(new Intent(SecondActivity.this, MainActivity.class));
                //finish();
            }
        });
    }
}
