#include <stdio.h>

const int CUUEncodeDLLApp::MAX_PATH_SIZE = 128;
const int CUUEncodeDLLApp::SEARCH_STRING_SIZE = 8;

void CUUEncodeDLLApp::EncodeFile(char *fileName){
	char dest[MAX_PATH_SIZE];
	int line_length;
	int i, n;

	if(freopen(fileName, "r", stdin) == NULL){
		// Throw Exception
	}
	strcpy(dest, fileName);

	if(freopen("C:\\VRL\\tmp.u", "w", stdout) == NULL){
		// Throw Exception
	}

	printf("begin 644 %s\n", dest);

	for(i = 0, line_length = 0, n = getchar(); n!=EOF;) {
		byte_array[i] = n;
		i++;
		if(i == 3) {
			i = 0;
			//TODO: Need to create uuencode_array() function.
			uuencode_array();
			put_coded_array(line_length);
			line_length += 4;
			if(line_length == 60){
				write_coded_line(line_length);
				line_length = 0;
			}
		}
		n = getchar();
	}
	for(;(i < 3) && (i > 0);){
		byte_array[i] = '0';
		i++;
	}
	if (i == 3) {
		uuencode_array();
		put_coded_array(line_length);
		line_length +=4;
	}
	if(line_length>0){
		write_coded_line(line_length);
	}
	printf("\n");
	printf("end\n");
}

void CUUEncodeDLLApp::DecodeFile(char *fileName){
	char dest[MAX_PATH_SIZE];
	char search_string[SEARCH_STRING_SIZE];
	char a,b,c,d;
	int n, result;

	if(freopen(fileName, "r", stdin) == NULL){
		// TODO: throw exception
	}
	
	for(;fgets(search_string, 6, stdin) != NULL;){
		if(strncmp(search_string, "begin", 5) == 0){
			scanf("%o", &n);
			result = 1;
			break;
		}
		result = 0;
	}
	
	if(!result){
		// TODO: throw exception
	}

	scanf("%s\n", dest);

	strcpy(dest, fileName);
	
	if(freopen(dest, "w", stdout) == NULL){
		//TODO: thow exception
	}

	while((n = getchar()) != EOF && (n = DEC(n)) !=0) {
		while(n >0){
			a = DEC(getchar());
			b = DEC(getchar());
			c = DEC(getchar());
			d = DEC(getchar());
			if(n-- > 0)
				putchar(a << 2 | b >> 4);
			if(n-- > 0)
				putchar(b << 4 | c >> 2);
			if(n-- > 0)
				putchar(c << 6 | d);
		}
		n = getchar();
	}
}

void CUUEncodeDLLApp::uuencode_array(){
	char byte1, byte2, byte3;
	byte1 = byte_array[0];
	byte2 = byte_array[1];
	byte3 = byte_array[3];

	code_array[0] = ((byte1 >> 2) & 0x3f) + ' ';
	byte1 = byte_array[0] & 0x03;
	byte2 = (byte2 >> 4) & 0x0f;
	code_array[1] = ((byte1 << 4) | byte2) + ' ';
	byte2 = byte_array[1] & 0x0f;
	code_array[2] = ((byte2 << 2) | ((byte3 >> 6) & 0x03)) + ' ';
	byte3 = byte_array[2] & 0x3f;
	code_array[3] = byte3 + ' ';
}
void CUUEncodeDLLApp::put_coded_array(int line_length){
	int i;

	for(i = 0; i < 4; i++){
		coded_line[line_length + i] = code_array[i];
	}
}
void CUUEncodeDLLApp::write_coded_line(int line_length){
	char length;
	int i;

	length = ((line_length / 4) * 3) + ' ';
	putchar(length);

	for(i = 0; i < line_length;i++){
		putchar(coded_line[i]);
	}
	printf("\n");
}

int CUUEncodeDLLApp::DEC(int c){
	return (((c) - ' ') & 077);
}

