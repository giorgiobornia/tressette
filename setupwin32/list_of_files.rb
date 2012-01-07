# We want generate a list of file to pack into a zip

GEN_SRC_LIST = 1

start_dir = "C:/Projects/cpp/tressette_sf/out"
out_file_list = "C:/Projects/cpp/tressette_sf/setupwin32/out_file_list.txt"

if GEN_SRC_LIST == 1
	start_dir = "C:/Projects/cpp/tressette_sf"
	out_file_list = "C:/Projects/cpp/tressette_sf/setupwin32/src_file_list.txt"
end

##
# scan the root dir and create a list of all files in it
class FileScanDir
  attr_accessor :result_list  

  def initialize
    @explore_dir = []
    @filter = []
    @result_list = []
  end
  
  ##
  # Add an array of directories to be filtered
  def add_dir_filter (filter)
  	@filter = filter
  end
  
  ##
  # Scan a root dir and list all files. Exclude filtered directory
  def scan_dir (dirname)
    puts "*** Inspect: " + dirname
    Dir.foreach(dirname) do |filename|
      path_cand = dirname + "/" + filename
      if File.directory?(path_cand)
        #exams directories
        if (filename != "." && filename != "..")
          unless @filter.index(filename)
            #directory not filtered
          	@explore_dir.push(path_cand)
          end
        end
      else
        # file to be listed
        @result_list.push(path_cand)
      end #file.directory?
    end
    next_dir = @explore_dir.pop
    scan_dir(next_dir) if next_dir 
  end  
end

if $0 == __FILE__
   fscd = FileScanDir.new
   fscd.add_dir_filter( ["CVS", ".svn", "Debug", "Release", "setupwin32"] )
   fscd.scan_dir(start_dir)
   fscd.result_list.each{|f| puts f}
   File.open(out_file_list, "w") do |file|
   	 fscd.result_list.each do |item| 
       file << item
       file << "\n"
     end
     puts "File list created #{out_file_list}"
   end
end

