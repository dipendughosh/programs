package com.dipendughosh.fragmenttofragmentcommunicationdemo;


import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;


/**
 * A simple {@link Fragment} subclass.
 */
public class MessageFragment extends Fragment {

    private EditText editText;
    private Button button;
    OnMessageSendListner messageSendListner;


    public MessageFragment() {
        // Required empty public constructor
    }

    public interface OnMessageSendListner {

        public void onMessageSend(String message);
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);

        Activity activity = (Activity) context;

        try {
            messageSendListner = (OnMessageSendListner) activity;
        }
        catch (ClassCastException e) {
            throw new ClassCastException(activity.toString() + "must override onMessageReadListner");
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_message, container, false);
        editText = view.findViewById(R.id.txt_message);
        button = view.findViewById(R.id.btn);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String message = editText.getText().toString();
                messageSendListner.onMessageSend(message);
            }
        });
        // Inflate the layout for this fragment
        return view;
    }

    @Override
    public void onResume() {
        super.onResume();
        editText.setText("");
    }
}
