from heapq import heappush, heappop, heapify
from collections import defaultdict

def huffman_encoding(data):
    if not data:
        return None, None
    
    freq = defaultdict(int)
    for char in data:
        freq[char] += 1
    
    heap = [[weight, [char, ""]] for char, weight in freq.items()]
    heapify(heap)
    
    while len(heap) > 1:
        left = heappop(heap)
        right = heappop(heap)
        for pair in left[1:]:
            pair[1] = '0' + pair[1]
        for pair in right[1:]:
            pair[1] = '1' + pair[1]
        heappush(heap, [left[0] + right[0]] + left[1:] + right[1:])
    
    huffman_code = dict(heappop(heap)[1:])
    
    encoded_data = ''.join([huffman_code[char] for char in data])
    
    return encoded_data, huffman_code

def huffman_decoding(encoded_data, huffman_code):
    if not encoded_data or not huffman_code:
        return None
    
    inv_huffman_code = {code: char for char, code in huffman_code.items()}
    
    decoded_data = ""
    code = ""
    for bit in encoded_data:
        code += bit
        if code in inv_huffman_code:
            decoded_data += inv_huffman_code[code]
            code = ""
    
    return decoded_data

# example usage
data = "hello world"
encoded_data, huffman_code = huffman_encoding(data)
print("Encoded data:", encoded_data)
decoded_data = huffman_decoding(encoded_data, huffman_code)
print("Decoded data:", decoded_data)
