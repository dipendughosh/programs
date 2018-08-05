package com.dipendughosh.registrationform;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class ShowDataActivity extends AppCompatActivity {

    private TextView tvName;
    private TextView tvEmail;
    private TextView tvPassword;
    private TextView tvGender;
    private Button btnBack;
    private Button btnProceed;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_show_data);

        Intent intent=getIntent();

        String name=intent.getStringExtra("name");
        String email=intent.getStringExtra("email");
        String password=intent.getStringExtra("password");
        String gender=intent.getStringExtra("gender");

        tvName=(TextView) findViewById(R.id.tvName);
        tvEmail=(TextView)findViewById(R.id.tvEmail);
        tvPassword=(TextView) findViewById(R.id.tvPassword);
        tvGender=(TextView) findViewById(R.id.tvGender);

        tvName.setText(name);
        tvEmail.setText(email);
        tvPassword.setText(password);
        tvGender.setText(gender);

        btnBack=(Button)findViewById(R.id.btnBack);

        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(ShowDataActivity.this,SignUpActivity.class);

                startActivity(intent);
            }
        });

        btnProceed=(Button)findViewById(R.id.btnProceed);

        btnProceed.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(ShowDataActivity.this,VisibilityActivity.class);

                startActivity(intent);
            }
        });
    }
}
