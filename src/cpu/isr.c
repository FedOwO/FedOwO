#include "isr.h"
#include "../libc/mem/mem.h"
#include "../driver/screen/screen.h"
#include "../libc/strings/strings.h"

void set_idt_gate(int n, unsigned int handler);
void set_idt();

isr_t interrupt_handlers[256];
void isr_setup() {
    kprint("Setting up isr...");
    set_idt_gate(0, (unsigned long)isr0);
    set_idt_gate(1, (unsigned long)isr1);
    set_idt_gate(2, (unsigned long)isr2);
    set_idt_gate(3, (unsigned long)isr3);
    set_idt_gate(4, (unsigned long)isr4);
    set_idt_gate(5, (unsigned long)isr5);
    set_idt_gate(6, (unsigned long)isr6);
    set_idt_gate(7, (unsigned long)isr7);
    set_idt_gate(8, (unsigned long)isr8);
    set_idt_gate(9, (unsigned long)isr9);
    set_idt_gate(10, (unsigned long)isr10);
    set_idt_gate(11, (unsigned long)isr11);
    set_idt_gate(12, (unsigned long)isr12);
    set_idt_gate(13, (unsigned long)isr13);
    set_idt_gate(14, (unsigned long)isr14);
    set_idt_gate(15, (unsigned long)isr15);
    set_idt_gate(16, (unsigned long)isr16);
    set_idt_gate(17, (unsigned long)isr17);
    set_idt_gate(18, (unsigned long)isr18);
    set_idt_gate(19, (unsigned long)isr19);
    set_idt_gate(20, (unsigned long)isr20);
    set_idt_gate(21, (unsigned long)isr21);
    set_idt_gate(22, (unsigned long)isr22);
    set_idt_gate(23, (unsigned long)isr23);
    set_idt_gate(24, (unsigned long)isr24);
    set_idt_gate(25, (unsigned long)isr25);
    set_idt_gate(26, (unsigned long)isr26);
    set_idt_gate(27, (unsigned long)isr27);
    set_idt_gate(28, (unsigned long)isr28);
    set_idt_gate(29, (unsigned long)isr29);
    set_idt_gate(30, (unsigned long)isr30);
    set_idt_gate(31, (unsigned long)isr31);
    kprint("Done!\n");

    kprint("Remapping irq...");
    port_byte_out(0x20, 0x11);
    port_byte_out(0xA0, 0x11);
    port_byte_out(0x21, 0x20);
    port_byte_out(0xA1, 0x28);
    port_byte_out(0x21, 0x04);
    port_byte_out(0xA1, 0x02);
    port_byte_out(0x21, 0x01);
    port_byte_out(0xA1, 0x01);
    port_byte_out(0x21, 0x0);
    port_byte_out(0xA1, 0x0);
    kprint("Done!\n");

    kprint("Setting up irq...");
    set_idt_gate(32, (unsigned long)irq0);
    set_idt_gate(33, (unsigned long)irq1);
    set_idt_gate(34, (unsigned long)irq2);
    set_idt_gate(35, (unsigned long)irq3);
    set_idt_gate(36, (unsigned long)irq4);
    set_idt_gate(37, (unsigned long)irq5);
    set_idt_gate(38, (unsigned long)irq6);
    set_idt_gate(39, (unsigned long)irq7);
    set_idt_gate(40, (unsigned long)irq8);
    set_idt_gate(41, (unsigned long)irq9);
    set_idt_gate(42, (unsigned long)irq10);
    set_idt_gate(43, (unsigned long)irq11);
    set_idt_gate(44, (unsigned long)irq12);
    set_idt_gate(45, (unsigned long)irq13);
    set_idt_gate(46, (unsigned long)irq14);
    set_idt_gate(47, (unsigned long)irq15);
    kprint("Done!\n");

    kprint("Load idt...");
    set_idt();
    kprint("Done!\n");
}

/* To print the message which defines every exception */
char *exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

void isr_handler(registers_t r) {
    kprint("received interrupt: ");
    char s[3];
    int_to_ascii(r.int_no, s);
    kprint(s);
    kprint("\n");
    kprint(exception_messages[r.int_no]);
    kprint("\n");
}

void register_interrupt_handler(unsigned char n, isr_t handler) {
    interrupt_handlers[n] = handler;
}

void irq_handler(registers_t r) {
    /* After every interrupt we need to send an EOI to the PICs
     * or they will not send another interrupt again */
    if (r.int_no >= 40) port_byte_out(0xA0, 0x20); /* slave */
    port_byte_out(0x20, 0x20); /* master */

    /* Handle the interrupt in a more modular way */
    if (interrupt_handlers[r.int_no] != 0) {
        isr_t handler = interrupt_handlers[r.int_no];
        handler(r);
    }
}
