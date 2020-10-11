module queue#(parameter QUEUE_DEPTH=4,
				parameter QUEUE_WIDTH=69)
				(input logic clk, ren, wen, empty, full,
				input logic [(QUEUE_WIDTH-1):0] din,
				output logic [(QUEUE_WIDTH-1):0] dout);
	
	parameter DTH_BIT=$clog2(QUEUE_DEPTH);
	parameter MX_DTH_BIT=$clog2(QUEUE_DEPTH)-1;
	
	logic [(QUEUE_WIDTH-1):0] _data [(QUEUE_DEPTH-1):0];
	logic _empty, _full;
	logic [MX_DTH_BIT:0] _head=DTH_BIT'b0000, _tail=DTH_BIT'b0000;
	
	//Deal with empty and full. The initial value of _empty and _full are 1 and 0 respectively.
	assign _empty=(_tail==_head)?1:0;
	assign _full=(_tail+1==_head)?1:0;
	
	always_ff@(posedge clk) begin
		//Deal with write. When it's full, one can not write although in theory, one can still first read a value and then write a value.  
		if(wen & !_full) begin
			_data[_tail]<=din;
			_tail<=_tail+1;
		end else;
		
		//Read. Note one need at least wait two cycles to get output because write and read operations happen simutaneously. When the first element is written, the old value is still empty so read will resolve to nothing.
		if(ren & !_empty) begin
			dout<=_data[_head];
			_head<=_head+1;
		end else;
		
	end
	
	assign empty=_empty;
	assign full=_full;
						
endmodule: queue