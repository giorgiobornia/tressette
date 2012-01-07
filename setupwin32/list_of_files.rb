# We want generate a list of file to pack into a zip


# crea i files con le liste per lo script pack_filelist_in_zip.rb
class GenSrcForPackager
  
  def initialize
    @script_dir = File.dirname(__FILE__)
    
    
  end
  
  def std_filters 
    @fscd.add_dir_filter( ["CVS", ".svn", "Debug", "Release", "setupwin32"] )
    @fscd.add_file_filter(['GfxWidtget3.exp', 'GfxWidtget3.lib', 'GfxWidtget3.pdb', 'GfxWidtget3_d.dll', 'GfxWidtget3_d.exp', 'GfxWidtget3_d.ilk', 
                          'GfxWidtget3_d.lib', 'GfxWidtget3_d.pdb', 'tre_d.exe', 'tre_d.ilk',
                          'org.eclipse.cdt.core.prefs', 'tressette.xml', 'trace_coregame.txt', 
                          'GfxWidtget3.vcproj.FRANK.igor.user', 'CxxTest_1_Run.plg', 'CxxTest_2_Build.plg', 
                          'TreClientVs6.vcproj.FRANK.igor.user', 'TreClientVs6.suo', 'TreClientVs6.ncb' ])
  end
  
  def create_out_list
    @fscd = FileScanDir.new
    std_filters
    start_dir = File.expand_path(File.join(@script_dir, '../out'))
    out_file_list = File.expand_path(File.join(@script_dir, "out_file_list.txt"))
    run(start_dir, out_file_list)
  end

  def create_source_list
    @fscd = FileScanDir.new
    std_filters
    @fscd.add_file_filter(['tre.exe', 'GfxWidtget3.dll'])
	  start_dir = File.expand_path(File.join(@script_dir, '..'))
	  out_file_list = File.expand_path(File.join(@script_dir, "src_file_list.txt"))
    run(start_dir, out_file_list)
  end
  
  def run(start_dir, out_file_list)
    puts "Generate #{out_file_list} starting on #{start_dir}"
    
    @fscd.scan_dir(start_dir)
    @fscd.result_list.each{|f| puts f}
    File.open(out_file_list, "w") do |file|
      @fscd.result_list.each do |item| 
        file << item
        file << "\n"
      end
      puts "File list created #{out_file_list}"
    end
  end
  
end

##
# scan the root dir and create a list of all files in it
class FileScanDir
  attr_accessor :result_list, :dir_list  

  def initialize
    @explore_dir = []
    @filter_dir = []
    @result_list = []
    @filter_file = []
    @dir_list = []
  end
  
  def log(str)
    puts str
  end
  
  ##
  # Add an array of directories to be filtered
  def add_dir_filter(filter)
    @filter_dir = filter
  end
  
  ##
  # Add an array of file that don't belong to the list
  def add_file_filter(file_filter)
    @filter_file << file_filter
    @filter_file = @filter_file.flatten
  end
  
  
  ##
  # Scan a root dir and list all files. Exclude filtered directory
  def scan_dir (dirname)
    log "*** Inspect: " + dirname
    Dir.foreach(dirname) do |filename|
      path_cand = File.join(dirname , filename)
      if File.directory?(path_cand)
        #exams directories
        if (filename != "." && filename != "..")
          unless @filter_dir.index(filename)
            #directory not filtered
            @explore_dir.push(path_cand)
            @dir_list << path_cand
          end
        end
      else
        # file to be listed
        unless file_is_filtered?(path_cand)
          # file is not filtered
          #p path_cand
          @result_list.push(path_cand)
        end
      end #file.directory?
    end
    next_dir = @explore_dir.pop
    scan_dir(next_dir) if next_dir 
  end # end scan dir
  
  ##
  # Check if a file belongs to a filtered list
  def file_is_filtered?(path_cand)
    filename = File.basename(path_cand)
    ix = @filter_file.index(filename)
    if ix
      log "FILTER: #{path_cand}" 
      return true
    else
      return false
    end
  end
  
  ##
  # Write the list into a file
  def write_filelist(out_file_list)
    result_list.each{|f| log f}
    File.open(out_file_list, "w") do |file|
        result_list.each do |item| 
        file << item
        file << "\n"
      end
      log "File list created #{out_file_list}"
    end 
  end 
end#end class FileScanDir


if $0 == __FILE__
  gen = GenSrcForPackager.new
  gen.create_out_list
  gen.create_source_list
  
  
end

