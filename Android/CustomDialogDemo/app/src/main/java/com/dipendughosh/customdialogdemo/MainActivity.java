package com.dipendughosh.customdialogdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import java.util.List;

public class MainActivity extends AppCompatActivity implements MyDialog.ToppingsSelectionListner {

    private TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = findViewById(R.id.textView);
    }

    public void showDialog(View view) {

        MyDialog myDialog = new MyDialog();
        myDialog.show(getSupportFragmentManager(), "my dialog");
    }

    @Override
    public void onToppingsSelected(List<String> topping) {
        String selection = "";

        for (String top : topping ) {
            selection = selection + top + " ";
        }

        textView.setText(selection);
    }
}
