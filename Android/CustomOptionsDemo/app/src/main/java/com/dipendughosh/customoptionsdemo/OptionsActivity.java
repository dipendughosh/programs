package com.dipendughosh.customoptionsdemo;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

public class OptionsActivity extends AppCompatActivity {

    private static final String PANEL_INSTALLED = "Num installed";
    private static final String APP_PREFS = "AppPrefs";
    private RadioGroup radio_group_install_size;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_options);

        createRadioButtons();
        int savedValue = getNumPanelsInstalled(this);
        Toast.makeText(this, "Saved Value " + savedValue, Toast.LENGTH_SHORT).show();
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
                    Toast.makeText(OptionsActivity.this, "You clicked " + numPanel, Toast.LENGTH_SHORT).show();
                    saveNumPanelsInstalled(numPanel);
                }
            });
            radio_group_install_size.addView(radioButton);

            //select default button
            if (numPanel == getNumPanelsInstalled(this)) {
                radioButton.setChecked(true);
            }
        }

    }

    public static Intent makeIntent(Context context) {
        Intent intent = new Intent(context, OptionsActivity.class);
        return intent;
    }

    private void saveNumPanelsInstalled(int numPanel) {
        SharedPreferences prefs = this.getSharedPreferences(APP_PREFS, MODE_PRIVATE);
        SharedPreferences.Editor editor = prefs.edit();
        editor.putInt(PANEL_INSTALLED, numPanel);
        editor.apply();
    }

    static public int getNumPanelsInstalled(Context context) {
        SharedPreferences prefs = context.getSharedPreferences(APP_PREFS, MODE_PRIVATE);
        int defaultValue = context.getResources().getInteger(R.integer.default_num_solar_panel);
        return prefs.getInt(PANEL_INSTALLED,defaultValue);
    }
}
