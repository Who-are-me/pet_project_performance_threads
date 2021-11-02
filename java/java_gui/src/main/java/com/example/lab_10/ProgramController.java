package com.example.lab_10;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import static java.lang.StrictMath.*;

public class ProgramController {
    private Lab10 l10;
    private double m_time;

    @FXML
    private TextField threads;
    @FXML
    private TextField steps;
    @FXML
    private TextField result;
    @FXML
    private TextField time;

    private void updateFields() {
        result.setText("" + l10.getData());
        time.setText("" + m_time);
    }

    @FXML
    protected void onRunButtonClick() {
        try {
            if (threads.getText().equals("") || steps.getText().equals("")) {
                throw new Exception("Error input data, please check input data.");
            }

            l10 = new Lab10();
            l10.setCountThreads(Integer.parseInt(threads.getText()));
            l10.setIntegralFunction((begin, step) -> (step * (sin(2 * (begin + step / 2.0)) * cos(3 * (begin + step / 2.0)))));
            m_time = System.currentTimeMillis();
            l10._run_(0.0, 3.14159265358979323846/2, Integer.parseInt(steps.getText()));
            m_time = System.currentTimeMillis() - m_time;

            updateFields();

        }
        catch (Exception exception) {
            System.out.println(exception);
        }
    }
}