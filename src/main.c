#include"SimpleMOC_header.h"

int main( int argc, char * argv[] )
{
	int version = 0;
	logo(version);
	srand(time(NULL));

	Input input = get_input();
	print_input_summary(input);

	Params params = build_tracks( input );

	double keff = 1.0;
	int num_iters = 100;
	for( int i = 0; i < num_iters; i++)
	{
		keff = transport_sweep(params, input);
	}

	free_2D_tracks( params.tracks_2D );
	free_tracks( params.tracks );

	return 0;
}
