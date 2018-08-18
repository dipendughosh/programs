package com.dipendughosh.customdialogdemo;

import android.app.Activity;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.DialogFragment;
import android.support.v7.app.AlertDialog;
import android.view.LayoutInflater;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class MyDialog extends DialogFragment {

    private List<String> mSelectedItems;

    public interface ToppingsSelectionListner {
        public void onToppingsSelected(List<String> topping);
    }

    ToppingsSelectionListner selectionListner;

    @NonNull
    @Override
    public Dialog onCreateDialog(@Nullable Bundle savedInstanceState) {

        mSelectedItems = new ArrayList<>();

        AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());

        /*
        //Custom dialog
        LayoutInflater inflater = getActivity().getLayoutInflater();
        builder.setView(inflater.inflate(R.layout.custome_dialog_layout, null));

        builder.setPositiveButton("sign in", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        });
        builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        });
*/
        //Display check box
        builder.setTitle("Pic a Toppings");
        builder.setMultiChoiceItems(R.array.toppings, null, new DialogInterface.OnMultiChoiceClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which, boolean isChecked) {
                String[] items = getActivity().getResources().getStringArray(R.array.toppings);

                if(isChecked) {
                    mSelectedItems.add(items[which]);
                }
                else if (mSelectedItems.contains(items[which])) {
                    mSelectedItems.remove(items[which]);
                }
            }
        });
        builder.setPositiveButton("Ok", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                String final_selection = "";
                for (String item : mSelectedItems) {
                    final_selection = final_selection + "\n" + item;
                }
                selectionListner.onToppingsSelected(mSelectedItems);
                Toast.makeText(getActivity(), final_selection, Toast.LENGTH_SHORT).show();
            }
        });
        builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        });

        return builder.create();
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);

        Activity activity = (Activity) context;

        try {
            selectionListner = (ToppingsSelectionListner) activity;
        }
        catch (ClassCastException e) {
            throw new ClassCastException(activity.toString() + "Must implement");
        }
    }
}
