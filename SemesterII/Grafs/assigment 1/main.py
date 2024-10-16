from UI import *

if __name__ == '__main__':
    file_path = "graph3.txt"
    ui = UI(file_path)
    ui.run_console()

    graph1 = build_random_graph(7, 20)
    write_graph_to_file(graph1, "random_graph1.txt")

    graph2 = build_random_graph(6, 40)
    write_graph_to_file(graph2, "random_graph2.txt")
    