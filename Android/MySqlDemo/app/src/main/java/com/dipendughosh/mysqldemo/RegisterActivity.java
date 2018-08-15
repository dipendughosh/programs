package com.dipendughosh.mysqldemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class RegisterActivity extends AppCompatActivity {

    private EditText name;
    private EditText surname;
    private EditText age;
    private EditText username;
    private EditText password;
    private String str_name;
    private String str_surname;
    private String str_age;
    private String str_username;
    private String str_password;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        name = (EditText) findViewById(R.id.et_name);
        surname = (EditText) findViewById(R.id.et_surname);
        age = (EditText) findViewById(R.id.et_age);
        username = (EditText) findViewById(R.id.et_username);
        password = (EditText) findViewById(R.id.et_password);

    }

    public void onReg(View view) {
        str_name = name.getText().toString();
        str_surname = surname.getText().toString();
        str_age = age.getText().toString();
        str_username = username.getText().toString();
        str_password = password.getText().toString();

        String type = "register";
        BackgroundWorker backgroundWorker = new BackgroundWorker(this);
        backgroundWorker.execute(type, str_name, str_surname, str_age, str_username, str_password);
    }
}
