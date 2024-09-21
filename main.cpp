#include <algorithm>
#include <iostream>
#include <gtk/gtk.h>
#include "peorcaso.h"
#include "mejorcaso.h"
#include "promedio.h"
#include <cairo.h>

using namespace std;


vector<double> benchmark_data;

vector<double> idealbenchmark_data;


static gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    // Establecer el color de fondo (gris claro)
    cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);
    cairo_paint(cr);

    // Dibujar el eje X e Y
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0); // Color negro
    cairo_set_line_width(cr, 2.0);
    cairo_move_to(cr, 50, 550); // Eje X
    cairo_line_to(cr, 750, 550);
    cairo_stroke(cr);

    cairo_move_to(cr, 50, 550); // Eje Y
    cairo_line_to(cr, 50, 50);
    cairo_stroke(cr);

    // Etiqueta de ejes
    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, 14);
    cairo_move_to(cr, 400, 580);
    cairo_show_text(cr, "N=100");

    cairo_save(cr);
    cairo_move_to(cr, 35, 380);
    cairo_rotate(cr, -M_PI / 2);
    cairo_show_text(cr, "Tiempo de Ejecución (ns)");
    cairo_restore(cr);


    cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); // Color rojo para la gráfica
    cairo_set_line_width(cr, 2.0);

    if (!benchmark_data.empty()) {
        int x_base = 100;
        int y_base = 550;
        int x_increment = 200;

        // Encontrar el valor máximo de benchmark para escalar correctamente
        double max_value = *std::max_element(benchmark_data.begin(), benchmark_data.end());
        if (max_value == 0) {
            max_value = 1;
        }

        // Escalamos los valores para que quepan en la gráfica (altura máxima 500 px)
        double scale_factor = 450.0 / max_value;

        // Moverse al primer punto
        cairo_move_to(cr, x_base, y_base - benchmark_data[0] * scale_factor);

        // Dibujar la línea para cada punto
        for (size_t i = 1; i < benchmark_data.size(); ++i) {
            cairo_line_to(cr, x_base + i * x_increment, y_base - benchmark_data[i] * scale_factor);
        }
        cairo_stroke(cr);

        // Dibujar pequeños círculos en los puntos de datos y los valores en ns
        cairo_set_source_rgb(cr, 0.0, 0.0, 1.0); // Color azul para los puntos
        int b = 3;
        string a = "(Mejor caso)";
        for (size_t i = 0; i < benchmark_data.size(); ++i) {

            if(b == 2) {
                a = "(Caso Promedio)";
            }
            if(b == 1){
                a = "(Peor caso)";
            }
            double x_pos = x_base + i * x_increment;
            double y_pos = y_base - benchmark_data[i] * scale_factor;
            cairo_arc(cr, x_pos, y_pos, 5, 0, 2 * M_PI);  // Dibujar un círculo pequeño
            cairo_fill(cr);  // Rellenar el círculo

            // Mostrar el valor de tiempo al lado del punto
            cairo_set_source_rgb(cr, 0.0, 0.0, 0.0); // Color negro para el texto
            cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
            cairo_set_font_size(cr, 12);


            // Convertir el valor a cadena y mostrarlo
            std::string value_str = std::to_string(static_cast<int>(benchmark_data[i])) + " ns " + a;
            cairo_move_to(cr, x_pos + 10, y_pos - 10); // Posiciona el texto cerca del punto
            cairo_show_text(cr, value_str.c_str());
            b--;
        }
    }


        if (!idealbenchmark_data.empty()) {
            int x_base = 100;
            int y_base = 550;
            int x_increment = 200;  // Aumentamos el espaciado en el eje X


            double max_value = *std::max_element(idealbenchmark_data.begin(), idealbenchmark_data.end());
            if (max_value == 0) {
                max_value = 1;  // Evitar división por cero si los datos son todos ceros
            }


            double scale_factor = 450.0 / max_value;

            // Moverse al primer punto
            cairo_move_to(cr, x_base - 30, y_base - idealbenchmark_data[0] * scale_factor);

            // Dibujar la línea para cada punto
            for (size_t i = 1; i < idealbenchmark_data.size(); ++i) {
                cairo_line_to(cr, x_base + i * x_increment - 30, y_base - idealbenchmark_data[i] * scale_factor);
            }
            cairo_stroke(cr);


            cairo_set_source_rgb(cr, 0.0, 0.0, 1.0);
            int b = 3;
            string a = "(Mejor caso)";
            for (size_t i = 0; i < idealbenchmark_data.size(); ++i) {
                if(b == 2) {
                    a = "(Caso Promedio)";
                }
                if(b == 1){
                    a = "(Peor caso)";
                }

                double x_pos = x_base + i * x_increment;
                double y_pos = y_base - idealbenchmark_data[i] * scale_factor;
                cairo_arc(cr, x_pos - 30, y_pos, 5, 0, 2 * M_PI);  // Dibujar un círculo pequeño
                cairo_fill(cr);  // Rellenar el círculo

                // Mostrar el valor de tiempo al lado del punto
                cairo_set_source_rgb(cr, 0.0, 0.0, 0.0); // Color negro para el texto
                cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
                cairo_set_font_size(cr, 12);


                std::string value_str = std::to_string(static_cast<int>(idealbenchmark_data[i])) + " ns " + a;
                cairo_move_to(cr, x_pos + 10, y_pos - 50); // Posiciona el texto cerca del punto
                cairo_show_text(cr, value_str.c_str());
                b--;


            }
        }



    return FALSE;
}



static GtkWidget* create_window(GtkApplication* app) {
    GtkWidget *window;
    GtkWidget *drawing_area;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Benchmark Graph");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    // Crear un área de dibujo
    drawing_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), drawing_area);

    // Conectar la señal de dibujo
    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw), NULL);

    return window;
}
static void activate(GtkApplication* app, gpointer user_data) {
    GtkWidget *window = create_window(app);
    gtk_widget_show_all(window);
}




int main(int argc, char **argv) {
    std::cout << std::endl;


    double PB = peorcasoBubbleSort();
    double PS = peorcasoSelectionSort();
    double PM = peorcasoMergeSort();
    double PL = peorcasoLinkedListSearch();
    double PBST = peorcasoBSTInsert();
    cout << "<---------------------------<---------------------------------------->--------------------------->" << endl;

    std::cout << std::endl;

    double MB = mejorBubbleSort();
    double MS = mejorSelectionSort();
    double MM = mejorMergeSort();
    double MLS = mejorLinkedListSearch();
    double MBST = mejorcasoBSTInsert();

    std::cout << std::endl;



    cout << "<---------------------------<---------------------------------------->--------------------------->" << endl;
    double PRB = promedioBubbleSort();
    double PRS = promedioSelectionSort();
    double PRM = promedioMergeSort();
    double PRLS = promedioLinkedListSearch();
    double PRBST = promediocasoBSTInsert();



    std::cout << std::endl;

    string casos;
    // Pedir al usuario que escriba algo
    std::cout << "Escribe una opción (B, S, M, Ls, BST): ";
    std::cin >> casos;

    if (casos == "B" || casos == "b") {
        benchmark_data.push_back(MB);  // Mejor caso
        benchmark_data.push_back(PRB);   // Caso promedio
        benchmark_data.push_back(PB);   // Peor caso
        idealbenchmark_data.push_back(1000);
        idealbenchmark_data.push_back(10000);
        idealbenchmark_data.push_back(10000);
    } else if (casos == "S" || casos == "s") {
        benchmark_data.push_back(MS);
        benchmark_data.push_back(PRS);
        benchmark_data.push_back(PS);
        idealbenchmark_data.push_back(10000);
        idealbenchmark_data.push_back(10000);
        idealbenchmark_data.push_back(10000);
    } else if (casos == "M" || casos == "m") {
        benchmark_data.push_back(MM);
        benchmark_data.push_back(PRM);
        benchmark_data.push_back(PM);
        idealbenchmark_data.push_back(664);
        idealbenchmark_data.push_back(664);
        idealbenchmark_data.push_back(664);
    } else if (casos == "Ls" || casos == "LS" || casos == "ls") {
        benchmark_data.push_back(MLS);
        benchmark_data.push_back(PRLS);
        benchmark_data.push_back(PL);
        idealbenchmark_data.push_back(1);
        idealbenchmark_data.push_back(100);
        idealbenchmark_data.push_back(100);
    } else if (casos == "BST" || casos == "bst") {
        benchmark_data.push_back(MBST);
        benchmark_data.push_back(PRBST);
        benchmark_data.push_back(PBST);
        idealbenchmark_data.push_back(6.64);
        idealbenchmark_data.push_back(6.64);
        idealbenchmark_data.push_back(100);
    } else {
        cout << "Opción no válida." << endl;
    }

    cout << "LÍNEA NEGRA: tasa de crecimiento esperada" << endl;
    cout << "LÍNEA ROJA: tasa de crecimiento obtenida" << endl;


    for(double i : benchmark_data) {
        cout << i << endl;
    }


    GtkApplication *app;
    int status;

    app = gtk_application_new("org.example.benchmark", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;

}


