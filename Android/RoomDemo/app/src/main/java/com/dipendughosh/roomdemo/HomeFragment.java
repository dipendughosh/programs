package com.dipendughosh.roomdemo;

import android.content.Context;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;


public class HomeFragment extends Fragment implements View.OnClickListener{

    private Button BnAdd;
    private Button BnView;
    private Button BnDelete;
    private Button BnUpdate;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_home, container, false);
        BnAdd = view.findViewById(R.id.bn_add_contact);
        BnAdd.setOnClickListener(this);
        BnView = view.findViewById(R.id.bn_view_contact);
        BnView.setOnClickListener(this);
        BnDelete = view.findViewById(R.id.bn_delete_contact);
        BnDelete.setOnClickListener(this);
        BnUpdate = view.findViewById(R.id.bn_update_contact);
        BnUpdate.setOnClickListener(this);
        // Inflate the layout for this fragment
        return view;
    }

    @Override
    public void onClick(View v) {
        switch(v.getId()) {
            case R.id.bn_add_contact:
                MainActivity.fragmentManager.beginTransaction().replace(R.id.fragment_container, new AddUserFragment()).addToBackStack(null).commit();
                break;
            case R.id.bn_view_contact:
                MainActivity.fragmentManager.beginTransaction().replace(R.id.fragment_container, new ReadUserFragment()).addToBackStack(null).commit();
                break;
            case R.id.bn_delete_contact:
                MainActivity.fragmentManager.beginTransaction().replace(R.id.fragment_container, new DeleteUserFragment()).addToBackStack(null).commit();
                break;
            case R.id.bn_update_contact:
                MainActivity.fragmentManager.beginTransaction().replace(R.id.fragment_container, new UpdateUserFragment()).addToBackStack(null).commit();
                break;
        }
    }
}
