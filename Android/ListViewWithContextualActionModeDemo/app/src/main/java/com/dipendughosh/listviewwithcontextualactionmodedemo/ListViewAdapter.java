package com.dipendughosh.listviewwithcontextualactionmodedemo;

import android.app.Activity;
import android.content.Context;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v7.widget.ActivityChooserView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class ListViewAdapter extends ArrayAdapter {

    private List<String> Fruits = new ArrayList<>();
    private Context context;

    public ListViewAdapter(List<String> Fruits, Context context) {
        super(context,R.layout.item_layout,Fruits);
        this.context = context;
        this.Fruits = Fruits;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {

        LayoutInflater inflater = ((Activity)context).getLayoutInflater();
        View view = inflater.inflate(R.layout.item_layout, parent, false);

        TextView FruitName = view.findViewById(R.id.fruit_name);
        FruitName.setText(Fruits.get(position));

        CheckBox checkBox = view.findViewById(R.id.checkBox);

        if(MainActivity.isActionMode) {
            checkBox.setVisibility(View.VISIBLE);
        }
        else {
            checkBox.setVisibility(View.GONE);
        }

        checkBox.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

                int position = (int) buttonView.getTag();

                if (MainActivity.UserSelection.contains(Fruits.get(position))) {
                    MainActivity.UserSelection.remove(Fruits.get(position));
                }
                else {
                    MainActivity.UserSelection.add(Fruits.get(position));
                }
                MainActivity.actionMode.setTitle(MainActivity.UserSelection.size() + " item selected");
            }
        });
        return view;
    }

    public void removeItem(List<String> items) {
        for (String item : items) {
            Fruits.remove(item);
        }
        notifyDataSetChanged();
    }
}
