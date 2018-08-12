package com.dipendughosh.switchactivitydemo;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class SecondActivity extends AppCompatActivity {

    private static final String EXTRA_NAME = "com.dipendughosh.switchactivitydemo.SecondActivity the name";
    private static final String EXTRA_AGE = "com.dipendughosh.switchactivitydemo.SecondActivity the age";
    private Button btnEndSecond;
    //private String name;
    //private int age;
    private PetRock rock;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        extractDataFromIntent();
        setupEndButton();
    }

    private void extractDataFromIntent() {
        Intent intent = getIntent();
        //name = intent.getStringExtra(EXTRA_NAME);
        //age = intent.getIntExtra(EXTRA_AGE, 0);
        String name = intent.getStringExtra(EXTRA_NAME);
        int age = intent.getIntExtra(EXTRA_AGE, 0);
        rock = new PetRock(name, age);
    }

    private void setupEndButton() {
        btnEndSecond = (Button) findViewById(R.id.btnEndSecond);
        btnEndSecond.setText("NAME : " + rock.getName() + " AGE : " + rock.getAge());
        btnEndSecond.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(SecondActivity.this, "Clicked, end second", Toast.LENGTH_SHORT).show();
                rock.setName("joda");
                rock.setAge(20);;
                finish();
                //Common Bug: intent is to launch MainActivity
                //Intent intent = new Intent(SecondActivity.this, MainActivity.class);
                //startActivity(intent);
            }
        });
    }

    /*public static Intent makeIntent(Context context, String name, int age) {
        Intent intent = new Intent(context, SecondActivity.class);
        intent.putExtra(EXTRA_NAME, name);
        intent.putExtra(EXTRA_AGE, age);
        return intent;

    }*/

    public static Intent makeIntent(Context context, PetRock rocky) {
        Intent intent = new Intent(context, SecondActivity.class);
        intent.putExtra(EXTRA_NAME, rocky.getName());
        intent.putExtra(EXTRA_AGE, rocky.getAge());
        return intent;

    }
}
