package com.pmobile.prova1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

public class Boletim extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_boletim);
        this.carregarDisciplinasAdapter();
        this.carregarPeriodosAdapter();
    }

    private void carregarDisciplinasAdapter() {
        Spinner spnDisciplinas = findViewById(R.id.spnDisciplinas);
        ArrayAdapter adapterDisciplinas = new ArrayAdapter<String>(this, android.R.layout.simple_expandable_list_item_1);
        adapterDisciplinas.addAll("Matemática", "História", "Informática", "Geografia", "Português");
        spnDisciplinas.setAdapter(adapterDisciplinas);
    }

    private void carregarPeriodosAdapter() {
        Spinner spnPeriodos = findViewById(R.id.spnPeriodos);
        ArrayAdapter adapterPeriodos = new ArrayAdapter<String>(this, android.R.layout.simple_expandable_list_item_1);
        adapterPeriodos.addAll( "Diurno", "Noturno", "Matutino", "Vespertino");
        spnPeriodos.setAdapter(adapterPeriodos);
    }

    public void clickRegistrar(View view) {
        EditText edtAvaliacao1 = findViewById(R.id.edtAvaliacao1);
        EditText edtAvaliacao2 = findViewById(R.id.edtAvaliacao2);
        EditText edtAvaliacao3 = findViewById(R.id.edtAvaliacao3);
        TextView txtExibirResultados = findViewById(R.id.txtExibirResultados);
        Spinner spnDisciplinas = findViewById(R.id.spnDisciplinas);
        Spinner spnPeriodos = findViewById(R.id.spnPeriodos);

        String disciplina = spnDisciplinas.getSelectedItem().toString();
        String periodo = spnPeriodos.getSelectedItem().toString();
        if(edtAvaliacao1.getText().toString().equals("") ||
                edtAvaliacao2.getText().toString().equals("") ||
                edtAvaliacao3.getText().toString().equals("")) {
            return;
        }
        Double notaAvaliacao1 = Double.parseDouble(edtAvaliacao1.getText().toString());
        Double notaAvaliacao2 = Double.parseDouble(edtAvaliacao2.getText().toString());
        Double notaAvaliacao3 = Double.parseDouble(edtAvaliacao3.getText().toString());
        Double media;
        String resultado = "Reprovado";

        switch (periodo) {
            case "Noturno":
                media = (((notaAvaliacao1 * 3) + (notaAvaliacao2 * 4) + (notaAvaliacao3 * 3)) / 10);
                if (media >= 6) {
                    resultado = "Aprovado";
                }
                break;
            default:
                media = (notaAvaliacao1 + notaAvaliacao2 + notaAvaliacao3) / 3;
                if (media >= 7) {
                    resultado = "Aprovado";
                }
                break;
        }

        txtExibirResultados.setText(String.format(
                "Disciplina: %s\n Período: %s\n Média: %.2f\n Resultado: %s",
                disciplina, periodo, media, resultado));

        edtAvaliacao1.setText("");
        edtAvaliacao2.setText("");
        edtAvaliacao3.setText("");
        spnDisciplinas.setSelection(0);
        spnPeriodos.setSelection(0);

    }
}