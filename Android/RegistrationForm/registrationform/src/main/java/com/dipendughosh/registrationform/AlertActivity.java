package com.dipendughosh.registrationform;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.TestLooperManager;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class AlertActivity extends AppCompatActivity {

    private TextView tvName;
    private TextView tvAccNo;
    private TextView tvBal;
    private TextView tvLogin;
    private EditText etUsername;
    private EditText etPassword;
    private Button btnBal;
    private Button btnName;
    private Button btnAccNo;
    private Button btnLogin;
    private Button btnBack;
    private Button btnProceed;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_alert);

        tvName=(TextView)findViewById(R.id.tvName);
        tvAccNo=(TextView)findViewById(R.id.tvAccNo);
        tvBal=(TextView)findViewById(R.id.tvBal);
        tvLogin=(TextView)findViewById(R.id.tvLogin);

        btnName=(Button)findViewById(R.id.btnName);
        btnAccNo=(Button)findViewById(R.id.btnAccNo);
        btnBal=(Button)findViewById(R.id.btnBal);
        btnLogin=(Button)findViewById(R.id.btnLogin);

        btnName.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                tvName.setText("Name : Dipendu");
            }
        });

        btnAccNo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                tvAccNo.setText("AccNo : HDFC1234");
            }
        });

        btnBal.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                View view1= LayoutInflater.from(AlertActivity.this).inflate(R.layout.activity_log_in,null);

                etUsername=(EditText)view1.findViewById(R.id.etUsername);
                etPassword=(EditText)view1.findViewById(R.id.etPassword);

                AlertDialog.Builder builder=new AlertDialog.Builder(AlertActivity.this);

                builder.setMessage("Are you sure?")
                        .setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int which) {
                                tvBal.setText("Balance : 1000");
                            }
                        })
                        .setNegativeButton("Cancel",null);

                AlertDialog alert=builder.create();
                alert.show();
            }
        });

        btnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                View view1= LayoutInflater.from(AlertActivity.this).inflate(R.layout.activity_log_in,null);

                etUsername=(EditText)view1.findViewById(R.id.etUsername);
                etPassword=(EditText)view1.findViewById(R.id.etPassword);

                AlertDialog.Builder builder=new AlertDialog.Builder(AlertActivity.this);

                builder.setMessage("Login Here")
                        .setView(view1)
                        .setPositiveButton("Login", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int which) {

                                String username=etUsername.getText().toString();
                                String password=etPassword.getText().toString();

                                if(username.equals("Dipendu") && password.equals("Dipendu")) {
                                    tvLogin.setText("Login Successful");
                                }
                                else {
                                    tvLogin.setText("Login Failed");
                                }
                            }
                        })
                        .setNegativeButton("Cancel",null)
                        .setCancelable(false);

                AlertDialog alert=builder.create();
                alert.show();
            }
        });

        btnBack=(Button)findViewById(R.id.btnBack);

        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(AlertActivity.this,WebViewActivity.class);

                startActivity(intent);
            }
        });

        btnProceed=(Button)findViewById(R.id.btnProceed);

        btnProceed.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(AlertActivity.this,MenuActivity.class);

                startActivity(intent);
            }
        });
    }

    @Override
    public void onBackPressed() {

        AlertDialog.Builder builder=new AlertDialog.Builder(AlertActivity.this);

        builder.setTitle("Exit App?")
                .setMessage("Are you sure?")
                .setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int which) {
                        AlertActivity.super.onBackPressed();
                    }
                })
                .setNegativeButton("Cancel",null)
                .setCancelable(false);

        AlertDialog alert=builder.create();
        alert.show();

    }
}
