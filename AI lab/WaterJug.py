from collections import deque

def water_jug_problem(jug1_cap, jug2_cap, target, target_jug):
    # Initialize visited set and queue for BFS
    visited = set()
    queue = deque([(0, 0, [])])  # (jug1, jug2, path)
    shortest_solution = None

    while queue:
        jug1, jug2, path = queue.popleft()

        # Skip if state already visited
        if (jug1, jug2) in visited:
            continue

        # Add current state to visited
        visited.add((jug1, jug2))
        current_path = path + [(jug1, jug2)]

        # Check if target is reached in specified jug
        if (target_jug == 1 and jug1 == target) or (target_jug == 2 and jug2 == target):
            if shortest_solution is None or len(current_path) < len(shortest_solution):
                shortest_solution = current_path
            continue

        # Generate all possible next states
        # Fill jug2 first (your suggested solution starts with filling jug2)
        if jug2 < jug2_cap:
            queue.append((jug1, jug2_cap, current_path))
        
        # Fill jug1
        if jug1 < jug1_cap:
            queue.append((jug1_cap, jug2, current_path))
        
        # Empty jug2
        if jug2 > 0:
            queue.append((jug1, 0, current_path))
        
        # Empty jug1
        if jug1 > 0:
            queue.append((0, jug2, current_path))
        
        # Pour from jug2 to jug1
        if jug2 > 0 and jug1 < jug1_cap:
            pour = min(jug2, jug1_cap - jug1)
            queue.append((jug1 + pour, jug2 - pour, current_path))
        
        # Pour from jug1 to jug2
        if jug1 > 0 and jug2 < jug2_cap:
            pour = min(jug1, jug2_cap - jug2)
            queue.append((jug1 - pour, jug2 + pour, current_path))

    return shortest_solution

def print_solution(path):
    print("\nSolution Path:")
    print("(Jug1, Jug2)")
    print("-" * 20)
    for step in path:
        print(f"{step}")


# Get input from user
jug1_capacity = int(input("Enter capacity of jug 1: "))
jug2_capacity = int(input("Enter capacity of jug 2: "))
target = int(input("Enter target amount: "))

#ask user to enter which jug is supposed to have the final target amount
while True:
    target_jug = int(input("Enter target jug (1 or 2): "))
    if target_jug in [1, 2]:
        break
    print("Please enter either 1 or 2!")

solution = water_jug_problem(jug1_capacity, jug2_capacity, target, target_jug)

if solution:
    print_solution(solution)
    print(f"\nTarget of {target} units water is achieved!")
else:
    print("\nNo solution exists!")

