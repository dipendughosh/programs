package com.dipendughosh.customoptionsdemo;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Button btnShowOptions;
    private TextView txtNoPanels;
    private TextView txtFinalCost;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setupOptionsButton();
        refreshScreen();
    }

    private void setupOptionsButton() {
        btnShowOptions = (Button) findViewById(R.id.btnShowOptions);
        btnShowOptions.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = OptionsActivity.makeIntent(MainActivity.this);
                startActivity(intent);
            }
        });
    }

    private void refreshScreen() {
        //refresh num panels display
        txtNoPanels = (TextView) findViewById(R.id.txtNoPanels);
        int numPanels = OptionsActivity.getNumPanelsInstalled(this);
        txtNoPanels.setText(numPanels + "");

        //cost
        txtFinalCost = (TextView) findViewById(R.id.txtFinalCost);
        int cost = numPanels * 1000;
        txtFinalCost.setText("$" + cost);
    }

    @Override
    protected void onResume() {
        super.onResume();
        refreshScreen();
    }
}
