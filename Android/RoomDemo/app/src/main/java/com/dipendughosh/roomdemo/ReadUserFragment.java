package com.dipendughosh.roomdemo;


import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import java.util.List;


/**
 * A simple {@link Fragment} subclass.
 */
public class ReadUserFragment extends Fragment {

    private TextView Txt_Display;

    public ReadUserFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_read_user, container, false);
        Txt_Display = view.findViewById(R.id.txt_display);

        List<User> users = MainActivity.myaAppDatabase.myDao().getUsers();

        String info = "";

        for (User user: users) {

            int id = user.getId();
            String name = user.getName();
            String email = user.getEmail();

            info = info+"\n\nId : " + id + "\nName : " + name + "\nEmail : " + email;

        }

        Txt_Display.setText(info);
        // Inflate the layout for this fragment
        return view;
    }

}
