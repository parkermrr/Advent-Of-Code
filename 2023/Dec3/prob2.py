import numpy as np
import re

in_file = open("in.txt", "r")

schematic = []
positions = []
for line in in_file:
  line_array = []
  positions.append(re.finditer(r'\d+', line))
  for char in line:
    if char != '\n':
      line_array.append(char)
  schematic.append(np.array(line_array))
schematic = np.array(schematic)

out_sum = 0
gear_potentials = {}
for idx in range(schematic.shape[0]):
  for match in positions[idx]:
    start_row_idx = idx - 1 if idx - 1 > 0 else idx
    end_row_idx = idx + 2

    start_col_idx = match.start() - 1 if match.start() - 1 > 0 else match.start()
    end_col_idx = match.end() + 1

    match_matrix = schematic[start_row_idx:end_row_idx, start_col_idx:end_col_idx]
    for i in range(match_matrix.shape[0]):
      for j in range(match_matrix.shape[1]):
        if match_matrix[i,j] == '*':
          gear_idx = (start_row_idx + i, start_col_idx + j)
          if gear_idx in gear_potentials.keys():
            gear_potentials[gear_idx].append(match.group())
          else:
            gear_potentials[gear_idx] = [match.group()]

for key in gear_potentials:
  if len(gear_potentials[key]) == 2:
    out_sum += int(gear_potentials[key][0]) * int(gear_potentials[key][1])
          
print(out_sum)