ENTRY(_start)

. = 0x80000000;

SECTIONS {
	.text : ALIGN(4K) {
		PROVIDE(__text_start = .);
		*(.text);
		PROVIDE(__text_end = .);
	}
	.data : ALIGN(4K) {
		PROVIDE(__data_start = .);
		*(.data);
		PROVIDE(__data_end = .);
	}
	.bss : ALIGN(4K) {
		PROVIDE(__bss_start = .);
		*(.bss)
		PROVIDE(__global_pointer$ = .);
		PROVIDE(__bss_end = .);
	}
	
	PROVIDE(__heap_start = .);
	. = 0x88000000;
	PROVIDE(__kernel_stack_start = . - 0x80000);
	PROVIDE(__kernel_stack_end = .);
	PROVIDE(__heap_size = __kernel_stack_start - __heap_start);
}