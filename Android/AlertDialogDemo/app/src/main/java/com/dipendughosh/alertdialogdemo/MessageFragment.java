package com.dipendughosh.alertdialogdemo;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v7.app.AppCompatDialogFragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;

public class MessageFragment extends AppCompatDialogFragment {

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {

        //Create the view to show
        View v = LayoutInflater.from(getActivity()).inflate(R.layout.message_layout, null);


        //Create a button listner
        DialogInterface.OnClickListener listner = new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

                switch (which) {
                    case DialogInterface.BUTTON_POSITIVE:
                        Log.i("TAG", "You clicked the dialog button");
                        TextView tv = (TextView) getActivity().findViewById(R.id.txtMsg);
                        tv.setText("Hello World");
                        //close the main activity from which it came
                        //getActivity().finish();
                        break;
                    case DialogInterface.BUTTON_NEGATIVE:
                        break;
                }
            }
        };

        //Build the alert dialog
        return new AlertDialog.Builder(getActivity())
                              .setTitle("changing message")
                              .setView(v)
                              .setPositiveButton(android.R.string.ok, listner)
                              .setNegativeButton(android.R.string.cancel, listner)
                              .create();
    }
}
