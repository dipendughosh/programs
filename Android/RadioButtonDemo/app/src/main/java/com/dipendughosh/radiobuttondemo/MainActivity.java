package com.dipendughosh.radiobuttondemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private RadioGroup radio_group_install_size;
    private Button btnFindSelected;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        createRadioButtons();
        setupPrintSelected();
    }

    private void createRadioButtons() {
        radio_group_install_size = (RadioGroup) findViewById(R.id.radio_group_install_size);
        int[] numPanels = getResources().getIntArray(R.array.num_solar_panels);
        //Create the buttons
        for (int i = 0; i < numPanels.length; i++) {
            final int numPanel = numPanels[i];

            RadioButton radioButton = new RadioButton(this);
            radioButton.setText(getString(R.string.message, numPanel));
            radioButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    Toast.makeText(MainActivity.this, "You clicked " + numPanel, Toast.LENGTH_SHORT).show();
                }
            });
            radio_group_install_size.addView(radioButton);
        }
        
    }

    private void setupPrintSelected() {
        btnFindSelected = (Button) findViewById(R.id.btnFindSelected);
        btnFindSelected.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                radio_group_install_size = (RadioGroup) findViewById(R.id.radio_group_install_size);
                int idOfSelected = radio_group_install_size.getCheckedRadioButtonId();
                RadioButton radioButton = (RadioButton) findViewById(idOfSelected);
                String message = radioButton.getText().toString();

                Toast.makeText(MainActivity.this, "Selected buttons text is : " + message, Toast.LENGTH_SHORT).show();

            }
        });

    }

}
