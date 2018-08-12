package com.dipendughosh.switchactivitydemo;

import android.app.Activity;
import android.content.Intent;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private static final int REQUEST_CODE_GETMESSAGE = 1014;
    private Button btnLaunchSecond;
    private Button btnLaunchThird;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setupSecondLaunchButton();
        setupThirdLaunchButton();
    }

    private void setupSecondLaunchButton() {
        
        btnLaunchSecond = (Button) findViewById(R.id.btnLaunchSecond);
        btnLaunchSecond.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(MainActivity.this, "Clicked, launch second", Toast.LENGTH_SHORT).show();

                PetRock rocky = new PetRock("Charlie", 202);
                //Intent intent = new Intent(MainActivity.this, SecondActivity.class);
                //Intent intent = SecondActivity.makeIntent(MainActivity.this, "bob", 101);
                Intent intent = SecondActivity.makeIntent(MainActivity.this, rocky);
                startActivity(intent);
                //Kill the MainActivity
                //finish();
            }
        });
    }

    private void setupThirdLaunchButton() {
        btnLaunchThird = (Button) findViewById(R.id.btnLaunchThird);
        btnLaunchThird.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(MainActivity.this, "Clicked, launch third", Toast.LENGTH_SHORT).show();

                Intent intent = ThirdActivity.makeIntent(MainActivity.this);
                //startActivity(intent);
                startActivityForResult(intent, REQUEST_CODE_GETMESSAGE);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        switch(requestCode) {
            case REQUEST_CODE_GETMESSAGE:
                if (resultCode == Activity.RESULT_OK) {
                    //Get the message
                    String message = ThirdActivity.getResultMessage(data);

                    Toast.makeText(this, "Returned is " + message, Toast.LENGTH_SHORT).show();
                }
                else {
                    Toast.makeText(this, "User Cancled", Toast.LENGTH_SHORT).show();
                }

        }
    }
}
