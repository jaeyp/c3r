# Imports
import sys
import zlib
from hashlib import sha1

# Functions
def main():
	if len(sys.argv) != 2:
		print("wrong parameter")
		sys.exit()
	fname = sys.argv[1]
	decomp = zlib.decompress(open(fname, 'rb').read())
	print(decomp)

	hash_value = sha1(decomp).hexdigest()
	print(f'hash: {hash_value}')

if __name__ == '__main__':
	main()
