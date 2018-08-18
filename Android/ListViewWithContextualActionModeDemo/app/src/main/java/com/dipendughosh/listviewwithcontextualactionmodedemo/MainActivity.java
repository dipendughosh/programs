package com.dipendughosh.listviewwithcontextualactionmodedemo;

import android.app.PendingIntent;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.ActionMode;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.AbsListView;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private ListView listView;
    private ListViewAdapter adapter;
    private List<String> Fruits = new ArrayList<>();
    public static List<String> UserSelection = new ArrayList<>();
    public static ActionMode actionMode = null;

    public static boolean isActionMode = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        getFruits();

        listView = findViewById(R.id.mListView);
        listView.setChoiceMode(AbsListView.CHOICE_MODE_MULTIPLE_MODAL);
        listView.setMultiChoiceModeListener(modeListener);
        adapter  = new ListViewAdapter(Fruits, this);
        listView.setAdapter(adapter);
    }

    private void getFruits() {

        String[] items = getResources().getStringArray(R.array.fruits);

        for(String item : items) {
            Fruits.add(item);
        }
    }

    AbsListView.MultiChoiceModeListener modeListener = new AbsListView.MultiChoiceModeListener() {
        @Override
        public void onItemCheckedStateChanged(ActionMode mode, int position, long id, boolean checked) {

            if (UserSelection.contains(Fruits.get(position))) {
                UserSelection.remove(Fruits.get(position));
            }
            else {
                UserSelection.add(Fruits.get(position));
            }
            mode.setTitle(UserSelection.size() + " item selected");
        }

        @Override
        public boolean onCreateActionMode(ActionMode mode, Menu menu) {
            MenuInflater menuInflater = mode.getMenuInflater();
            menuInflater.inflate(R.menu.context_menu,menu);

            actionMode = mode;
            isActionMode = true;
            return true;
        }

        @Override
        public boolean onPrepareActionMode(ActionMode mode, Menu menu) {
            return false;
        }

        @Override
        public boolean onActionItemClicked(ActionMode mode, MenuItem item) {

            switch (item.getItemId()) {
                case R.id.action_delete:
                    adapter.removeItem(UserSelection);
                    displayMessage("deleted");
                    mode.finish();
                    return true;
                case R.id.action_share:
                    displayMessage("share");
                    mode.finish();
                    return true;
                default:
                    return false;
            }

        }

        @Override
        public void onDestroyActionMode(ActionMode mode) {

            actionMode = null;
            isActionMode = false;
            UserSelection.clear();
        }
    };

    private void displayMessage(String message) {
        //Snackbar.make(findViewById(R.id.rootView), message, Snackbar.LENGTH_LONG).show();
    }
}
