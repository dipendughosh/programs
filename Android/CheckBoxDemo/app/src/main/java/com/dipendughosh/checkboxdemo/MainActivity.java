package com.dipendughosh.checkboxdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private CheckBox check1;
    private CheckBox check2;
    private CheckBox check3;
    private Button button_sel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        addListenerOnButton();
        addListnerToCheckBox();
    }

    public void addListnerToCheckBox() {
        check1 = (CheckBox)findViewById(R.id.checkBox_dog);
        check1.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        if(((CheckBox)v).isChecked()) {
                            Toast.makeText(MainActivity.this,
                                    "Dog is selected",Toast.LENGTH_LONG).show();
                        }
                    }
                }
        );
    }

    public void addListenerOnButton() {
        check1 = (CheckBox)findViewById(R.id.checkBox_dog);
        check2 = (CheckBox)findViewById(R.id.checkBox_cat);
        check3 = (CheckBox)findViewById(R.id.checkBox_cow);
        button_sel = (Button)findViewById(R.id.button);

        button_sel.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        StringBuffer result = new StringBuffer();
                        result.append("Dog : ").append(check1.isChecked());
                        result.append("\nCat : ").append(check2.isChecked());
                        result.append("\nCow : ").append(check3.isChecked());

                        Toast.makeText(MainActivity.this,result.toString(),
                                Toast.LENGTH_LONG).show();
                    }
                }

        );

    }
}
