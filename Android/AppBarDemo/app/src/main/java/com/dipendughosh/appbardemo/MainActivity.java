package com.dipendughosh.appbardemo;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends OptionsMenuActivity {

    private Toolbar toolbar;
    private Button button;
    private final int change_item_id = 101;
    private boolean isItemAdd = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        button = findViewById(R.id.bn);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {

        MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.app_bar_menu, menu);

        /*to display only on main activity
        MenuItem.OnActionExpandListener onActionExpandListener = new MenuItem.OnActionExpandListener() {
            @Override
            public boolean onMenuItemActionExpand(MenuItem item) {
                Toast.makeText(MainActivity.this, "Action View Expand", Toast.LENGTH_SHORT).show();
                return true;
            }

            @Override
            public boolean onMenuItemActionCollapse(MenuItem item) {
                Toast.makeText(MainActivity.this, "Action View Collapsed", Toast.LENGTH_SHORT).show();
                return true;
            }
        };

        MenuItem searchItem = menu.findItem(R.id.action_search);
        searchItem.setOnActionExpandListener(onActionExpandListener);*/

        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

        /*
        to display only on main activity
        switch (item.getItemId()) {
            case R.id.action_share:
                Toast.makeText(this, "Share", Toast.LENGTH_SHORT).show();
                return true;

            case R.id.action_settings:
                Toast.makeText(this, "Setting", Toast.LENGTH_SHORT).show();
                return true;

            case R.id.action_search:
                Toast.makeText(this, "Search", Toast.LENGTH_SHORT).show();
                return true;

            default:
                return super.onOptionsItemSelected(item);
        }
        */
        return super.onOptionsItemSelected(item);
    }

    public void startAnotherActivity(View view) {

        startActivity(new Intent(this, SecondActivity.class));
    }

    public void manageChangeOption(View view) {

        if(!isItemAdd) {
            isItemAdd = true;
            button.setText("Remove Change Option");
            invalidateOptionsMenu();
        }
        else {
            isItemAdd = false;
            button.setText("Add Change Option");
            invalidateOptionsMenu();
        }
    }

    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {

        if (isItemAdd) {
            if (menu.findItem(change_item_id) == null) {
                MenuItem changeItem = menu.add(Menu.NONE, change_item_id,5,"change");
                changeItem.setIcon(R.drawable.ic_change);
                changeItem.setShowAsActionFlags(MenuItem.SHOW_AS_ACTION_ALWAYS);

                changeItem.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
                    @Override
                    public boolean onMenuItemClick(MenuItem item) {
                        return true;
                    }
                });
            }
        }
        else {
            menu.removeItem(change_item_id);
        }
        super.onPrepareOptionsMenu(menu);

        return true;
    }
}
