from asyncio import PriorityQueue
from exception import GraphException
from copy import deepcopy
from collections import deque
import random
import heapq
import sys
from queue import PriorityQueue

class Graph:
    _inbound : list
    _outbound : list
    _costs : list
    def __init__(self, vertices):

        self._outbound = dict()  # a dictionary that stores the outbound neighbours for a vertex
        self._inbound = dict()  # a dictionary that stores the inbound neighbours for a vertex
        self._costs = dict()  # a dictionary that stores the costs for an edge
        self._edge_id = dict()

        for vertex in range(vertices) :
            self._outbound[vertex] = []
            self._inbound[vertex] = []

        

    def is_edge(self, x, y):
        # a function that verifies if there is an edge between x and y (x,y - vertices)
        if x in self._outbound:
            if y in self._outbound[x]:
                return True
        return False
    def is_vertex(self, vertex:int) -> bool:
        return vertex < len(self._inbound) and vertex >=0
        
    @property
    def outbound(self):
        return self._outbound

    @property
    def inbound(self):
        return self._inbound
    
    def get_edge_id(self, x, y) -> int:
        return self._edge_id[(x, y)]

    @property
    def number_vertices(self) -> int:
        # a function that returns the number of vertices
        return len(self._outbound)

    @property
    def number_of_edges(self):
        # a function that returns the number of edges
        return len(self._costs)

    @property
    def costs(self):
        # a function that returns the dictionary of costs
        return self._costs

    def get_list_of_edges(self):
        edges = []
        for key, val in self._costs.items():
            edges.append((key[0], key[1], val))
        return edges[:]
    def get_vertices_count(self):
        return len(self._inbound)            
    def parse_vertices(self):
        # a function that returns an iterable of the vertices
        
        return list(range(self.get_vertices_count()))


    def find_edge(self, x, y):
        # a function that verifies if there is an edge between vertices x and y and returns the cost of it if yes or raises an exception otherwise
        
        return self._costs[(x, y)]

    def parse_outbound(self, vertex):
        # a function that returns an iterable of the outbound neighbours of vertex x or None if x is not a vertex
        
        return [(vertex, neighboar)for neighboar in self._outbound[vertex]]

    def parse_outbound_neighboar(self, vertex):
        return self._outbound[vertex][:]


    def parse_inbound(self, x):
        # a function that returns an iterable of the inbound neighbours of vertex x or None if x is not a vertex
        
        return [y for y in self._inbound[x]]

    def parse_outbound_with_costs(self, x):
        # a function that returns an iterable of the edge costs of the outbound neighbours of vertex x or None if x is not a vertex
       
        return [self._costs[(x, y)] for y in self._outbound[x]]

    def parse_inbound_with_costs(self, x):
        # a function that returns an iterable of the edge costs of the inbound neighbours of vertex x or None if x is not a vertex
        
        return [self._costs[(y, x)] for y in self._inbound[x]]

    def get_degree_out(self, x):
        # a function that returns the outbound degree of the vertex x if this one exists
        # if x not in self._outbound:
        #     raise GraphException("The given value is not a vertex 4.")
        return len(self._outbound[x])

    def get_degree_in(self, x):
        # a function that returns the inbound degree of the vertex x if this one exists
        # if x not in self._inbound:
        #     raise GraphException("The given value is not a vertex. 5")
        return len(self._inbound[x])

    def parse_inbound_neighbours(self, vertex):
        if not self.is_vertex(vertex):
            raise Exception()
        return self.inbound[vertex][:]
    def add_vertex(self, x):
        # a function that adds a vertex to the graph
        
        self._outbound[x] = []
        self._inbound[x] = []

    def remove_vertex(self, x):
        # a function that removes a vertex from the graph
        

        for y in self.parse_vertices():
            if x in self.parse_outbound(y):
                del self._costs[(y, x)]
                self._outbound[y].remove(x)
            if x in self.parse_inbound(y):
                del self._costs[(x, y)]
                self._inbound[y].remove(x)
        self._inbound.pop(x)
        self._outbound.pop(x)
    # complexity O(n log n)
    
    
    
    
    def get_cost(self, source : int, target :int):
        
        return self._costs[(source), target]
    
    def set_edge_id(self, x, y):
        while True:
            current_edge_id = random.randint(1, 10**6)
            is_unique = True
            for val in self._edge_id.values():
                if current_edge_id == val:
                    is_unique = False
                    break
            if is_unique:
                break
      #  print("x, y:", x, y)
        self._edge_id[(x, y)] = current_edge_id

    def add_edge(self, x, y, cost):
        # a function that adds an edge to the graph where x and y are the vertices
        self._outbound[x].append(y)
        self._inbound[y].append(x)
        self._costs[(x, y)] = cost

    # self.set_edge_id(x, y)

        while True:
            current_edge_id = random.randint(1, 10**6)
            is_unique = True
            for val in self._edge_id.values():
                if current_edge_id == val:
                    is_unique = False
                    break
            if is_unique:
                break
        #print("x, y:", x, y)
        self._edge_id[(x, y)] = current_edge_id

    def remove_edge(self, x, y):
        # a function that removes an edge from the graph if it exists (where x and y are vertices)
        del self._costs[(x, y)]

        self._outbound[x].remove(y)
        self._inbound[y].remove(x)

    def make_copy(self):
        # a function that returns a copy of the graph
        return deepcopy(self)

    def modify_cost(self, x, y, cost):
        # a function that modifies the cost of an edge if it exists
        self._costs[(x, y)] = cost
    
    def find_the_lowest_walk(self, vertex1 : int, vertex2 : int):
        # finds a lowest length path between them, by using a forward breadth-first search from the starting vertex.

        queue = deque([vertex1])
        visited = set([vertex1])
        predecessors = {}

        while queue:

            current_vertex = queue.popleft()
            if current_vertex == vertex2:
                break
            for neighbor in self.parse_outbound_neighboar(current_vertex):
                if neighbor not in visited:
                    queue.append(neighbor)
                    visited.add(neighbor)
                    predecessors[neighbor] = current_vertex

        path = [vertex2]
        current_vertex = vertex2

        if vertex2 in predecessors:
            while current_vertex != vertex1:
                next_vertex = predecessors[current_vertex]
                path.append(next_vertex)
                current_vertex = next_vertex
            return path
        else:
            return None


        
    

    def dijkstra(graph, source, target):
        # Initialize distances with infinity for all vertices except the source.
        distances = {vertex: float('inf') for vertex in graph.parse_vertices()}
        distances[source] = 0

        # Initialize the priority queue with the source vertex and its distance.
        pq = PriorityQueue()
        pq.put((0, source))

        # Initialize predecessors.
        predecessors = {vertex: None for vertex in graph.parse_vertices()}

        while not pq.empty():
            current_distance, current_vertex = pq.get()

            for neighbor in graph.parse_outbound_neighboar(current_vertex):
                # Calculate the new distance.
                new_distance = current_distance + graph.get_cost(current_vertex, neighbor)

                if new_distance < distances[neighbor]:
                    distances[neighbor] = new_distance
                    predecessors[neighbor] = current_vertex
                    pq.put((new_distance, neighbor))

        # Reconstruct the path from target to source.
        path = []
        current_vertex = target
        while current_vertex is not None:
            path.insert(0, current_vertex)
            current_vertex = predecessors[current_vertex]

        return path

        
    def msp_prim(self, start_vertex):
        # Initialize the priority queue with the start vertex and its distance.
        pq = PriorityQueue()
        pq.put((0, start_vertex))

        # Initialize the set of visited vertices.
        visited = set()

        # Initialize the minimum spanning tree.
        msp = []

        while not pq.empty():
            current_cost, current_vertex = pq.get()

            if current_vertex in visited:
                continue

            visited.add(current_vertex)

            for neighbor in self.parse_outbound_neighboar(current_vertex):
                if neighbor not in visited:
                    pq.put((self.get_cost(current_vertex, neighbor), neighbor))
                    msp.append((current_vertex, neighbor))

        return msp
        
        
    

def build_random_graph(number_of_vertices, number_of_edges):
    # A function that receives 2 integers (number_of_vertices and number_of_edges) and generates and returns a random graph.
   # if 2 * number_of_edges > number_of_vertices * (number_of_vertices - 1):
    #    return False
    edge_set = set()
    while len(edge_set) < number_of_edges:
        x = random.randrange(number_of_vertices)
        y = random.randrange(number_of_vertices)
        z = random.randint(-20, 120)
        edge_set.add((x, y, z))

    generated_graph = Graph(range(number_of_vertices), edge_set)

    return generated_graph


    
    


def write_graph_to_file(graph, file_path):

#    A function that writes a given graph into a text file.
#   param graph: an object of class Graph
#    param file_path: a string representing the given file.

    f = open(file_path, "wt")
    first_line = str(graph.number_vertices) + " " + str(graph.number_of_edges) + "\n"
    f.write(first_line)
    
    for edge in graph.costs:
        line = str(edge[0]) + " " + str(edge[1]) + " " + str(graph.find_edge(edge[0], edge[1])) + "\n"
        f.write(line)
    for vertex in graph.parse_vertices():
        if len(graph.outbound[vertex]) == 0 and len(graph.inbound[vertex]) == 0:
            line = str(vertex) + "\n"
            f.write(line)
    f.close()


def read_graph(file_path)->Graph:

    with open(file_path, "r") as file:
        lines = file.readlines()
        vertices, edges = map(int, lines[0].split())
        result = Graph(vertices)

        # Construct outbound edges and costs directly
        result._outbound = {vertex: [] for vertex in range(vertices)}
        result._costs = {}

        for line in lines[1:]:
            x, y, cost = map(int, line.split())
            result._outbound[x].append(y)
            result._costs[(x, y)] = cost

    return result
 

# # finds a lowest length path between them, by using a forward breadth-first search from the starting vertex.

        # queue = deque([vertex1])  # Initialize a queue with the start vertex.
        # visited = set([vertex1])  # Initialize a set to keep track of visited vertices.
        # predecessors = {}  # Initialize a dictionary to store predecessors for path reconstruction.

        # # Explore outbound neighbors of the current vertex.
        # while queue:
        #     current_vertex = queue.popleft()
        #     if current_vertex == vertex2:
        #         break
        #     for neighbor in self.parse_outbound_neighboar(current_vertex):
        #         if neighbor not in visited:
        #             queue.append(neighbor)
        #             visited.add(neighbor)
        #             predecessors[neighbor] = current_vertex

        # # reconstruct the lowest length path from the start vertex to the end vertex.

        # path = [vertex2]  # Initialize the path with the end vertex.
        # current_vertex = vertex2  # Set the current vertex to the end vertex.

        # # if the end vertex has a predecessor, a path exists.

        # if vertex2 in predecessors:
        #     # goes until reaching the start_vertex
        #     while current_vertex != vertex1:
        #         next_vertex = predecessors[current_vertex]
        #         path.append(next_vertex)
        #         current_vertex = next_vertex
        #     return path
        # else:
        #     return None