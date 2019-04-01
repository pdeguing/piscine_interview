#include "header.h"

unsigned int	updatePlace(unsigned int parkingRow, int pos, int value) {
	return ((parkingRow & ~(1 << pos)) | ((value ? 1 : 0) << pos));
}
