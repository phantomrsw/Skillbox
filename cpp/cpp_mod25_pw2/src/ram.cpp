
int ram[8] = {16,7,6,5,4,3,2,1};

int read_ram(int addr){
    if(addr >= 0 && addr < 8) return ram[addr];
    else return 0;
}

void write_ram(int addr, int data){
    if(addr >= 0 && addr < 8) ram[addr] = data;
}