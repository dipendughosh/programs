package com.dipendughosh.registrationform;

import android.content.Intent;
import android.provider.MediaStore;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

public class SignUpActivity extends AppCompatActivity {

    private EditText etName;
    private EditText etEmail;
    private EditText etPassword;
    private RadioButton rbMale;
    private RadioButton rbFemale;
    private RadioGroup rgGender;
    private Button btnSighUp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_up);

        etName=(EditText)findViewById(R.id.etName);
        etEmail=(EditText)findViewById(R.id.etEmail);
        etPassword=(EditText)findViewById(R.id.etPassword);
        rbMale=(RadioButton)findViewById(R.id.rbMale);
        rbFemale=(RadioButton)findViewById(R.id.rbFemale);
        rgGender=(RadioGroup)findViewById(R.id.rgGender);
        btnSighUp=(Button)findViewById(R.id.btnSignUp);

        btnSighUp.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {

                final String name=etName.getText().toString();
                final String email=etEmail.getText().toString();
                final String password=etPassword.getText().toString();
                String gender="";
                /*if(rbMale.isChecked()) {
                    gender="Male";
                }
                else if(rbFemale.isChecked()) {
                    gender="Female";
                }*/
                int i=rgGender.getCheckedRadioButtonId();
                RadioButton rb=(RadioButton) rgGender.findViewById(i);
                gender=rb.getText().toString();

                Toast.makeText(SignUpActivity.this,"Name : " + name + "\nEmail : " + email + "\nPassword : " + password + "\nGender : " + gender,Toast.LENGTH_LONG).show();

                //System.out.println("Name : " + name + "\nEmail : " + email + "\nPassword : " + password + "\nGender : " + gender);

                Intent intent=new Intent(SignUpActivity.this, ShowDataActivity.class);

                intent.putExtra("name",name);
                intent.putExtra("email",email);
                intent.putExtra("password",password);
                intent.putExtra("gender",gender);

                startActivity(intent);
            }
        });
    }
}
