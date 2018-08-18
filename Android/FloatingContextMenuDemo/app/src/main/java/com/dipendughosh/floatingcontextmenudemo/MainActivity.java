package com.dipendughosh.floatingcontextmenudemo;

import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    private Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = findViewById(R.id.button);

        registerForContextMenu(button);
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        super.onCreateContextMenu(menu, v, menuInfo);

        MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.context_menu, menu);
    }

    @Override
    public boolean onContextItemSelected(MenuItem item) {

        switch (item.getItemId()){

            case R.id.actionn_add_playlist:
                displayMessage("Playlist");
                return true;
            case R.id.actionn_delete:
                displayMessage("Delete");
                return true;
            case R.id.actionn_info:
                displayMessage("Info");
                return true;
            case R.id.actionn_report:
                displayMessage("Report");
                return true;
            case R.id.actionn_share:
                displayMessage("Share");
                return true;
        }
        return super.onContextItemSelected(item);
    }

    private void displayMessage(String message) {

        Snackbar.make(findViewById(R.id.rootView), message, Snackbar.LENGTH_LONG).show();
    }
}
